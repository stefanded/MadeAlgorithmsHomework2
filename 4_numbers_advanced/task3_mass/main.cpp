/*

 */

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <optional>
#include <random>

/**
 * @brief Бинарное умножение по модулю.
 * @details Рекурсивный вариант функции.
 * @param a Первый множитель.
 * @param b Второй множитель.
 * @param module Модуль поля.
 * @return Произведение по модулю.
 */
uint64_t binprod(uint64_t a, uint64_t b, uint64_t module) {
    if (a == 0 || b == 0) {
        return 0;
    }
    assert(module != 1);
    if (b % 2 == 1)
        return (binprod(a, b - 1, module) + a) % module;
    else {
        auto half_prod = binprod(a, b / 2, module);
        return (half_prod + half_prod) % module;
    }
}

/**
 * @brief Бинарное возведение в степень по модулю.
 * @details Для не очень больших чисел (квадрат которых вмещается в uint64_t).
 * @param a Основание степени.
 * @param b Показатель степени.
 * @param module Модуль поля.
 * @return Результат возведения в степень.
 */
uint64_t binpow_small(uint64_t a, uint64_t b, uint64_t module) {
    uint64_t res = 1;
    while (b > 0) {
        if (b & 1) {
            res *= a;
            res %= module;
            --b;
        }
        a *= a;
        a %= module;
        b >>= 1;
    }
    return res;
}

/**
 * @brief Бинарное возведение в степень по модулю.
 * @details Для больших чисел (квадрат которых не вмещается в uint64_t).
 * @details Работает медленнее, чем аналог для маленьких чисел.
 * @param a Основание степени.
 * @param b Показатель степени.
 * @param module Модуль поля.
 * @return Результат возведения в степень.
 */
uint64_t binpow_large(uint64_t a, uint64_t b, uint64_t module) {
    uint64_t res = 1;
    while (b > 0) {
        if (b & 1) {
            res = binprod(res, a, module);
            --b;
        }
        a = binprod(a, a, module);
        b >>= 1;
    }
    return res;
}

/**
 * @brief Бинарное возведение в степень по модулю.
 * @details Выбирает нужную функцию для возведения.
 * @param a Основание степени.
 * @param b Показатель степени.
 * @param module Модуль поля.
 * @return Результат возведения в степень.
 */
uint64_t binpow(uint64_t a, uint64_t b, uint64_t module) {
    assert(!(a == 0 && b == 0));
    if (a == 0) {
        return 0;
    }
    if (b == 0) {
        return 1;
    }
    assert(module != 1);
    if (a < 1000000000ULL) {
        return binpow_small(a, b, module);
    } else {
        return binpow_large(a, b, module);
    }
}


std::vector<std::vector<uint64_t>> factorize(const std::vector<uint64_t> &numbers, const int8_t addition) {
    uint64_t max_number = *std::max_element(numbers.begin(), numbers.end()) + addition;
    std::vector<uint64_t> primes;
    std::vector<uint64_t> least_prime(max_number + 1, 0);

    for (uint64_t i = 2; i <= max_number; ++i) {
        if (least_prime[i] == 0) {
            least_prime[i] = i;
            primes.push_back(i);
        }
        for (const auto prime: primes) {
            if ((prime > least_prime[i]) || (prime * i > max_number)) {
                break;
            }
            least_prime[prime * i] = prime;
        }
    }

    std::vector<std::vector<uint64_t>> result;
    for (auto number: numbers) {
        result.emplace_back();
        number += addition;
        while (number != 1) {
            result.back().push_back(least_prime[number]);
            number /= least_prime[number];
        }
    }
    return result;
}

/**
 * @brief Поиск минимального первообразного корня по модулю p.
 * @param p Модуль поля.
 * @return Минимальный генератор.
 */
std::vector<uint64_t> find_min_generators(const std::vector<uint64_t> &modules) {
    auto all_factors = factorize(modules, -1);  // факторизуем p-1

    std::vector<uint64_t> generators;
    for (size_t i = 0; i < modules.size(); ++i) {
        const auto p = modules[i];
        const auto &factors = all_factors[i];
        for (uint64_t g = 2; g < p; ++g) {
            bool success = true;
            uint64_t current_factor = 0;
            for (auto factor : factors) {
                if (current_factor != factor)  // не проверяем дважды один и тот же делитель
                {
                    const auto gpd = binpow(g, (p - 1) / factor,
                                            p);  // проверяем минимально необходимый набор делителей
                    if (gpd == 1) {
                        success = false;  // g - не генератор
                    }
                    current_factor = factor;
                }
            }
            if (success) {
                generators.push_back(g);  // нашли генератор
                break;
            }
        }
    }
    return generators;
}

/**
 * @brief Поиск дискретного логарифма в конечном поле по модулю.
 * @param a Основание логарифма.
 * @param b Число под логарифмом.
 * @param n Модуль поля.
 * @return Значение логарифма, если оно существует.
 */
std::optional<uint64_t> discrete_logarithm(const uint64_t a, const uint64_t b, const uint64_t n) {
    auto k = static_cast<uint64_t>(std::sqrt(n) + 1);
    auto ak = binpow(a, k, n);
    while (ak == 1) {
        ++k;
        ak = binpow(a, k, n);
    }
    uint64_t current_aik = 1;
    std::map<uint64_t, size_t> apk;
    for (size_t r = 1; r <= k; ++r) {
        current_aik = binprod(current_aik, ak, n);
        apk[current_aik] = r;
    }
    uint64_t current_bai = b;
    for (size_t s = 1; s <= k; ++s) {
        current_bai = binprod(current_bai, a, n);
        auto r_iter = apk.find(current_bai);
        if (r_iter != apk.end()) {
            const auto r = r_iter->second;
            const auto x = r * k - s;
            if (x < n) {
                return x;
            }
        }
    }
    return std::nullopt;
}

/**
 * @brief Поиск дискретного корня в конечном поле по модулю. x^a=b (mod n)
 * @param a Показатель степени.
 * @param b Значение возведения в степень.
 * @param n Модуль поля.
 * @param g Генератор поля.
 * @return Значение логарифма, если оно существует.
 */
std::optional<uint64_t> discrete_sqrt(const uint64_t a, const uint64_t b, const uint64_t n, uint64_t g = 0) {
    if (b == 0) {
        return 0;
    }
    if (g == 0) {
        g = find_min_generators({n})[0];
    }
    auto gpa = binpow(g, a, n);
    auto y = discrete_logarithm(gpa, b, n);
    if (y.has_value()) {
        auto x = binpow(g, y.value(), n);
        return x;
    }
    return std::nullopt;
}

// Начало тестов

void test_from_task() {
    uint64_t a = 3;
    uint64_t b = 4;
    uint64_t n = 5;
    auto result = discrete_sqrt(a, b, n);
    assert(result.has_value());
    assert(binpow(result.value(), a, n) == b);
    assert(result.value() < n);
    a = 3;
    b = 1;
    n = 7;
    result = discrete_sqrt(a, b, n);
    assert(result.has_value());
    assert(binpow(result.value(), a, n) == b);
    assert(result.value() < n);
}

void test_binprod() {
    auto result = binprod(0, 1, 7);
    assert(result == 0);
    result = binprod(0, 4, 7);
    assert(result == 0);
    result = binprod(4, 0, 7);
    assert(result == 0);
    result = binprod(1, 0, 7);
    assert(result == 0);
    result = binprod(15, 15, 21);
    assert(result == 15);
    result = binprod(583, 49, 935);
    assert(result == 517);
    result = binprod(91, 37, 113);
    assert(result == 90);
    result = binprod(9999999999, 100000000001, 99999999999);
    assert(result == 19999999998);
}

void test_binpow() {
    auto result = binpow(0, 1, 7);
    assert(result == 0);
    result = binpow(0, 4, 7);
    assert(result == 0);
    result = binpow(4, 0, 7);
    assert(result == 1);
    result = binpow(1, 0, 7);
    assert(result == 1);
    result = binpow(15, 15, 21);
    assert(result == 15);
    result = binpow(583, 49, 935);
    assert(result == 583);
    result = binpow(91, 37, 113);
    assert(result == 61);
    result = binpow(99999999999, 100000000001, 999999999999);
    assert(result == 407240682858);
}

void run_all_tests() {
    test_from_task();
    test_binprod();
    test_binpow();
}

// Конец тестов

int main(int argc, char *argv[]) {
    //run_all_tests();
    //return 0;
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    if (argc > 1) {
        if (std::string(argv[1]) == "test")  // запуск тестов
        {
            run_all_tests();
            return 0;
        }
    }

    // Чтение входных данных
    size_t T{0};
    std::cin >> T;
    std::vector<std::tuple<uint64_t, uint64_t>> equations;
    std::vector<uint64_t> modules;
    equations.reserve(T);
    for (size_t i = 0; i < T; ++i) {
        uint64_t a, b, n{0};
        std::cin >> b >> a >> n;
        equations.emplace_back(a, b);
        modules.push_back(n);
    }

    auto generators = find_min_generators(modules);
    std::vector<std::optional<uint64_t>> results;
    results.reserve(T);
    for (size_t i = 0; i < equations.size(); ++i) {
        auto[a, b] = equations[i];
        results.push_back(discrete_sqrt(a, b, modules[i], generators[i]));
    }

    // Запись результата
    for (const auto &result : results) {
        if (result.has_value()) {
            std::cout << result.value();
        } else {
            std::cout << -1;
        }
        std::cout << "\n";
    }

    return 0;
}