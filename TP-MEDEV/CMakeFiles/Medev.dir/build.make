# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/eleve/Documents/C++/TP-MEDEV

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/eleve/Documents/C++/TP-MEDEV

# Include any dependencies generated for this target.
include CMakeFiles/Medev.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Medev.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Medev.dir/flags.make

CMakeFiles/Medev.dir/tests/gtests.cpp.o: CMakeFiles/Medev.dir/flags.make
CMakeFiles/Medev.dir/tests/gtests.cpp.o: tests/gtests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/eleve/Documents/C++/TP-MEDEV/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Medev.dir/tests/gtests.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Medev.dir/tests/gtests.cpp.o -c /home/eleve/Documents/C++/TP-MEDEV/tests/gtests.cpp

CMakeFiles/Medev.dir/tests/gtests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Medev.dir/tests/gtests.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/eleve/Documents/C++/TP-MEDEV/tests/gtests.cpp > CMakeFiles/Medev.dir/tests/gtests.cpp.i

CMakeFiles/Medev.dir/tests/gtests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Medev.dir/tests/gtests.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/eleve/Documents/C++/TP-MEDEV/tests/gtests.cpp -o CMakeFiles/Medev.dir/tests/gtests.cpp.s

CMakeFiles/Medev.dir/src/lib.cpp.o: CMakeFiles/Medev.dir/flags.make
CMakeFiles/Medev.dir/src/lib.cpp.o: src/lib.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/eleve/Documents/C++/TP-MEDEV/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Medev.dir/src/lib.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Medev.dir/src/lib.cpp.o -c /home/eleve/Documents/C++/TP-MEDEV/src/lib.cpp

CMakeFiles/Medev.dir/src/lib.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Medev.dir/src/lib.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/eleve/Documents/C++/TP-MEDEV/src/lib.cpp > CMakeFiles/Medev.dir/src/lib.cpp.i

CMakeFiles/Medev.dir/src/lib.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Medev.dir/src/lib.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/eleve/Documents/C++/TP-MEDEV/src/lib.cpp -o CMakeFiles/Medev.dir/src/lib.cpp.s

# Object files for target Medev
Medev_OBJECTS = \
"CMakeFiles/Medev.dir/tests/gtests.cpp.o" \
"CMakeFiles/Medev.dir/src/lib.cpp.o"

# External object files for target Medev
Medev_EXTERNAL_OBJECTS =

build/Medev: CMakeFiles/Medev.dir/tests/gtests.cpp.o
build/Medev: CMakeFiles/Medev.dir/src/lib.cpp.o
build/Medev: CMakeFiles/Medev.dir/build.make
build/Medev: build_gtest/lib/libgtest.a
build/Medev: CMakeFiles/Medev.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/eleve/Documents/C++/TP-MEDEV/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable build/Medev"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Medev.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Medev.dir/build: build/Medev

.PHONY : CMakeFiles/Medev.dir/build

CMakeFiles/Medev.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Medev.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Medev.dir/clean

CMakeFiles/Medev.dir/depend:
	cd /home/eleve/Documents/C++/TP-MEDEV && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/eleve/Documents/C++/TP-MEDEV /home/eleve/Documents/C++/TP-MEDEV /home/eleve/Documents/C++/TP-MEDEV /home/eleve/Documents/C++/TP-MEDEV /home/eleve/Documents/C++/TP-MEDEV/CMakeFiles/Medev.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Medev.dir/depend

