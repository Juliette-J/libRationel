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
CMAKE_SOURCE_DIR = /home/charline/Documents/IMAC/2A/IMAC2-PROG/Projet_PROG_MATHS/libRatio

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/charline/Documents/IMAC/2A/IMAC2-PROG/Projet_PROG_MATHS/libRatio/build

# Include any dependencies generated for this target.
include INTERFACE/CMakeFiles/Rational.dir/depend.make

# Include the progress variables for this target.
include INTERFACE/CMakeFiles/Rational.dir/progress.make

# Include the compile flags for this target's objects.
include INTERFACE/CMakeFiles/Rational.dir/flags.make

INTERFACE/CMakeFiles/Rational.dir/src/Rational.cpp.o: INTERFACE/CMakeFiles/Rational.dir/flags.make
INTERFACE/CMakeFiles/Rational.dir/src/Rational.cpp.o: ../myLib/src/Rational.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/charline/Documents/IMAC/2A/IMAC2-PROG/Projet_PROG_MATHS/libRatio/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object INTERFACE/CMakeFiles/Rational.dir/src/Rational.cpp.o"
	cd /home/charline/Documents/IMAC/2A/IMAC2-PROG/Projet_PROG_MATHS/libRatio/build/INTERFACE && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Rational.dir/src/Rational.cpp.o -c /home/charline/Documents/IMAC/2A/IMAC2-PROG/Projet_PROG_MATHS/libRatio/myLib/src/Rational.cpp

INTERFACE/CMakeFiles/Rational.dir/src/Rational.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Rational.dir/src/Rational.cpp.i"
	cd /home/charline/Documents/IMAC/2A/IMAC2-PROG/Projet_PROG_MATHS/libRatio/build/INTERFACE && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/charline/Documents/IMAC/2A/IMAC2-PROG/Projet_PROG_MATHS/libRatio/myLib/src/Rational.cpp > CMakeFiles/Rational.dir/src/Rational.cpp.i

INTERFACE/CMakeFiles/Rational.dir/src/Rational.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Rational.dir/src/Rational.cpp.s"
	cd /home/charline/Documents/IMAC/2A/IMAC2-PROG/Projet_PROG_MATHS/libRatio/build/INTERFACE && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/charline/Documents/IMAC/2A/IMAC2-PROG/Projet_PROG_MATHS/libRatio/myLib/src/Rational.cpp -o CMakeFiles/Rational.dir/src/Rational.cpp.s

# Object files for target Rational
Rational_OBJECTS = \
"CMakeFiles/Rational.dir/src/Rational.cpp.o"

# External object files for target Rational
Rational_EXTERNAL_OBJECTS =

INTERFACE/libRational.a: INTERFACE/CMakeFiles/Rational.dir/src/Rational.cpp.o
INTERFACE/libRational.a: INTERFACE/CMakeFiles/Rational.dir/build.make
INTERFACE/libRational.a: INTERFACE/CMakeFiles/Rational.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/charline/Documents/IMAC/2A/IMAC2-PROG/Projet_PROG_MATHS/libRatio/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libRational.a"
	cd /home/charline/Documents/IMAC/2A/IMAC2-PROG/Projet_PROG_MATHS/libRatio/build/INTERFACE && $(CMAKE_COMMAND) -P CMakeFiles/Rational.dir/cmake_clean_target.cmake
	cd /home/charline/Documents/IMAC/2A/IMAC2-PROG/Projet_PROG_MATHS/libRatio/build/INTERFACE && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Rational.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
INTERFACE/CMakeFiles/Rational.dir/build: INTERFACE/libRational.a

.PHONY : INTERFACE/CMakeFiles/Rational.dir/build

INTERFACE/CMakeFiles/Rational.dir/clean:
	cd /home/charline/Documents/IMAC/2A/IMAC2-PROG/Projet_PROG_MATHS/libRatio/build/INTERFACE && $(CMAKE_COMMAND) -P CMakeFiles/Rational.dir/cmake_clean.cmake
.PHONY : INTERFACE/CMakeFiles/Rational.dir/clean

INTERFACE/CMakeFiles/Rational.dir/depend:
	cd /home/charline/Documents/IMAC/2A/IMAC2-PROG/Projet_PROG_MATHS/libRatio/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/charline/Documents/IMAC/2A/IMAC2-PROG/Projet_PROG_MATHS/libRatio /home/charline/Documents/IMAC/2A/IMAC2-PROG/Projet_PROG_MATHS/libRatio/myLib /home/charline/Documents/IMAC/2A/IMAC2-PROG/Projet_PROG_MATHS/libRatio/build /home/charline/Documents/IMAC/2A/IMAC2-PROG/Projet_PROG_MATHS/libRatio/build/INTERFACE /home/charline/Documents/IMAC/2A/IMAC2-PROG/Projet_PROG_MATHS/libRatio/build/INTERFACE/CMakeFiles/Rational.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : INTERFACE/CMakeFiles/Rational.dir/depend

