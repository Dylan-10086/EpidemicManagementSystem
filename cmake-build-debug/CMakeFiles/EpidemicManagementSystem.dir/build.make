# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/zitao/Code/C:C++/EpidemicManagementSystem

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/zitao/Code/C:C++/EpidemicManagementSystem/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/EpidemicManagementSystem.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/EpidemicManagementSystem.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/EpidemicManagementSystem.dir/flags.make

CMakeFiles/EpidemicManagementSystem.dir/main.c.o: CMakeFiles/EpidemicManagementSystem.dir/flags.make
CMakeFiles/EpidemicManagementSystem.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zitao/Code/C:C++/EpidemicManagementSystem/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/EpidemicManagementSystem.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/EpidemicManagementSystem.dir/main.c.o -c /Users/zitao/Code/C:C++/EpidemicManagementSystem/main.c

CMakeFiles/EpidemicManagementSystem.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/EpidemicManagementSystem.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/zitao/Code/C:C++/EpidemicManagementSystem/main.c > CMakeFiles/EpidemicManagementSystem.dir/main.c.i

CMakeFiles/EpidemicManagementSystem.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/EpidemicManagementSystem.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/zitao/Code/C:C++/EpidemicManagementSystem/main.c -o CMakeFiles/EpidemicManagementSystem.dir/main.c.s

# Object files for target EpidemicManagementSystem
EpidemicManagementSystem_OBJECTS = \
"CMakeFiles/EpidemicManagementSystem.dir/main.c.o"

# External object files for target EpidemicManagementSystem
EpidemicManagementSystem_EXTERNAL_OBJECTS =

EpidemicManagementSystem: CMakeFiles/EpidemicManagementSystem.dir/main.c.o
EpidemicManagementSystem: CMakeFiles/EpidemicManagementSystem.dir/build.make
EpidemicManagementSystem: CMakeFiles/EpidemicManagementSystem.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/zitao/Code/C:C++/EpidemicManagementSystem/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable EpidemicManagementSystem"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/EpidemicManagementSystem.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/EpidemicManagementSystem.dir/build: EpidemicManagementSystem
.PHONY : CMakeFiles/EpidemicManagementSystem.dir/build

CMakeFiles/EpidemicManagementSystem.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/EpidemicManagementSystem.dir/cmake_clean.cmake
.PHONY : CMakeFiles/EpidemicManagementSystem.dir/clean

CMakeFiles/EpidemicManagementSystem.dir/depend:
	cd /Users/zitao/Code/C:C++/EpidemicManagementSystem/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/zitao/Code/C:C++/EpidemicManagementSystem /Users/zitao/Code/C:C++/EpidemicManagementSystem /Users/zitao/Code/C:C++/EpidemicManagementSystem/cmake-build-debug /Users/zitao/Code/C:C++/EpidemicManagementSystem/cmake-build-debug /Users/zitao/Code/C:C++/EpidemicManagementSystem/cmake-build-debug/CMakeFiles/EpidemicManagementSystem.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/EpidemicManagementSystem.dir/depend

