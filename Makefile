# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.

# The CMake executable.
CMAKE_COMMAND = /data/data/ru.iiec.cxxdroid/files/bin/cmake

# The command to remove a file.
RM = /data/data/ru.iiec.cxxdroid/files/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /storage/37DD-7B90/Android/data/com.manichord.mgit/files/repo/MadeAlgorithmsHomework2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /storage/37DD-7B90/Android/data/com.manichord.mgit/files/repo/MadeAlgorithmsHomework2

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/data/data/ru.iiec.cxxdroid/files/bin/cmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/data/data/ru.iiec.cxxdroid/files/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /storage/37DD-7B90/Android/data/com.manichord.mgit/files/repo/MadeAlgorithmsHomework2/CMakeFiles /storage/37DD-7B90/Android/data/com.manichord.mgit/files/repo/MadeAlgorithmsHomework2/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /storage/37DD-7B90/Android/data/com.manichord.mgit/files/repo/MadeAlgorithmsHomework2/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named task2_1

# Build rule for target.
task2_1: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 task2_1
.PHONY : task2_1

# fast build rule for target.
task2_1/fast:
	$(MAKE) -f 2_dynamics_advanced/task1/CMakeFiles/task2_1.dir/build.make 2_dynamics_advanced/task1/CMakeFiles/task2_1.dir/build
.PHONY : task2_1/fast

#=============================================================================
# Target rules for targets named task2_2

# Build rule for target.
task2_2: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 task2_2
.PHONY : task2_2

# fast build rule for target.
task2_2/fast:
	$(MAKE) -f 2_dynamics_advanced/task2/CMakeFiles/task2_2.dir/build.make 2_dynamics_advanced/task2/CMakeFiles/task2_2.dir/build
.PHONY : task2_2/fast

#=============================================================================
# Target rules for targets named task2_3

# Build rule for target.
task2_3: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 task2_3
.PHONY : task2_3

# fast build rule for target.
task2_3/fast:
	$(MAKE) -f 2_dynamics_advanced/task3/CMakeFiles/task2_3.dir/build.make 2_dynamics_advanced/task3/CMakeFiles/task2_3.dir/build
.PHONY : task2_3/fast

#=============================================================================
# Target rules for targets named task2_4

# Build rule for target.
task2_4: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 task2_4
.PHONY : task2_4

# fast build rule for target.
task2_4/fast:
	$(MAKE) -f 2_dynamics_advanced/task4/CMakeFiles/task2_4.dir/build.make 2_dynamics_advanced/task4/CMakeFiles/task2_4.dir/build
.PHONY : task2_4/fast

#=============================================================================
# Target rules for targets named task2_5

# Build rule for target.
task2_5: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 task2_5
.PHONY : task2_5

# fast build rule for target.
task2_5/fast:
	$(MAKE) -f 2_dynamics_advanced/task5/CMakeFiles/task2_5.dir/build.make 2_dynamics_advanced/task5/CMakeFiles/task2_5.dir/build
.PHONY : task2_5/fast

#=============================================================================
# Target rules for targets named task2_6

# Build rule for target.
task2_6: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 task2_6
.PHONY : task2_6

# fast build rule for target.
task2_6/fast:
	$(MAKE) -f 2_dynamics_advanced/task6/CMakeFiles/task2_6.dir/build.make 2_dynamics_advanced/task6/CMakeFiles/task2_6.dir/build
.PHONY : task2_6/fast

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... task2_1"
	@echo "... task2_2"
	@echo "... task2_3"
	@echo "... task2_4"
	@echo "... task2_5"
	@echo "... task2_6"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

