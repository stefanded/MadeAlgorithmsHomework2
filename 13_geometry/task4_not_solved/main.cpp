/*
 * Задача G. База в джунглях
 * Имя входного файла:jungle.in
 * Имя выходного файла:jungle.out
 * Ограничение по времени: 2 секунды
 * Ограничение по памяти: 256 мегабайт
 *
 * Глубоко в джунглях расположена военная база.
 * Она окружена n сторожевыми башнями с ультразвуковыми генераторами.
 * В этой задаче сторожевые башни считаются точками на плоскости.
 * Сторожевые башни генерируют ультразвуковое поле с помощью которого защищают все объекты,
 * расположенные строго внутри выпуклой оболочки сторожевых башен.
 * Не существует сторожевой башни строго внутри выпуклой оболочки и никакие три сторожевые башни не находятся на
 * одной прямой. Враг может уничтожить несколько башен.
 * Если такое происходит, защищаемая область уменьшается до выпуклой оболочки оставшихся башен.
 *
 * Командир базы хочет построить штаб внутри защищаемой области.
 * Чтобы максимизировать ее безопасность, он хочет максимизировать минимальное количество башен,
 * который должен унитчожить враг, чтобы оставить штаб без защиты.
 *
 * Формат входных данных
 * Первая строка входного файла содержит одно число n(3⩽n⩽50 000) — количество сторожевых башен.
 * Следующие n строк содержат декартовы координаты сторожевых башен, по одной паре встроке.
 * Все координаты являются целыми числами и не превосходят по модулю 10^6.
 * Башни описаны в порядке обхода их выпуклой оболочки по часовой стрелке.
 *
 * Формат выходных данных
 * Выведите в выходной файл количество сторожевых башен, которые должен уничтожить враг,
 * чтобы оставить штаб без защиты, если штаб будет расположен оптимально
 *
 * Примеры
 * Входные данные:
 * 3
 * 0 0
 * 50 50
 * 60 10
 * Выходные данные:
 * 1
 * Входные данные:
 * 5
 * 0 0
 * 0 10
 * 10 20
 * 20 10
 * 25 0
 * Выходные данные:
 * 2
 */

/*
 * Подробнее о:
 *
 */


#include <random>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <array>
#include <utility>
#include <iomanip>
#include <optional>


// Начало тестов

void test_from_task() {

}


void run_all_tests() {
    test_from_task();
}

// Конец тестов

int main(int argc, char *argv[]) {
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

    // Решение задачи
    

    return 0;
}
