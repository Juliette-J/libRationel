# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/juliettej/Documents/libRationel/libRatio

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/juliettej/Documents/libRationel/libRatio/build

# Include any dependencies generated for this target.
include myTest/CMakeFiles/myUnitTests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include myTest/CMakeFiles/myUnitTests.dir/compiler_depend.make

# Include the progress variables for this target.
include myTest/CMakeFiles/myUnitTests.dir/progress.make

# Include the compile flags for this target's objects.
include myTest/CMakeFiles/myUnitTests.dir/flags.make

myTest/CMakeFiles/myUnitTests.dir/src/sample_test.cpp.o: myTest/CMakeFiles/myUnitTests.dir/flags.make
myTest/CMakeFiles/myUnitTests.dir/src/sample_test.cpp.o: ../myTest/src/sample_test.cpp
myTest/CMakeFiles/myUnitTests.dir/src/sample_test.cpp.o: myTest/CMakeFiles/myUnitTests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/juliettej/Documents/libRationel/libRatio/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object myTest/CMakeFiles/myUnitTests.dir/src/sample_test.cpp.o"
	cd /home/juliettej/Documents/libRationel/libRatio/build/myTest && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT myTest/CMakeFiles/myUnitTests.dir/src/sample_test.cpp.o -MF CMakeFiles/myUnitTests.dir/src/sample_test.cpp.o.d -o CMakeFiles/myUnitTests.dir/src/sample_test.cpp.o -c /home/juliettej/Documents/libRationel/libRatio/myTest/src/sample_test.cpp

myTest/CMakeFiles/myUnitTests.dir/src/sample_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/myUnitTests.dir/src/sample_test.cpp.i"
	cd /home/juliettej/Documents/libRationel/libRatio/build/myTest && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/juliettej/Documents/libRationel/libRatio/myTest/src/sample_test.cpp > CMakeFiles/myUnitTests.dir/src/sample_test.cpp.i

myTest/CMakeFiles/myUnitTests.dir/src/sample_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/myUnitTests.dir/src/sample_test.cpp.s"
	cd /home/juliettej/Documents/libRationel/libRatio/build/myTest && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/juliettej/Documents/libRationel/libRatio/myTest/src/sample_test.cpp -o CMakeFiles/myUnitTests.dir/src/sample_test.cpp.s

# Object files for target myUnitTests
myUnitTests_OBJECTS = \
"CMakeFiles/myUnitTests.dir/src/sample_test.cpp.o"

# External object files for target myUnitTests
myUnitTests_EXTERNAL_OBJECTS =

myTest/myUnitTests: myTest/CMakeFiles/myUnitTests.dir/src/sample_test.cpp.o
myTest/myUnitTests: myTest/CMakeFiles/myUnitTests.dir/build.make
myTest/myUnitTests: INTERFACE/libRational.a
myTest/myUnitTests: /usr/lib64/libgtest_main.so.1.11.0
myTest/myUnitTests: /usr/lib64/libgtest.so.1.11.0
myTest/myUnitTests: myTest/CMakeFiles/myUnitTests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/juliettej/Documents/libRationel/libRatio/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable myUnitTests"
	cd /home/juliettej/Documents/libRationel/libRatio/build/myTest && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/myUnitTests.dir/link.txt --verbose=$(VERBOSE)
	cd /home/juliettej/Documents/libRationel/libRatio/build/myTest && /usr/bin/cmake -D TEST_TARGET=myUnitTests -D TEST_EXECUTABLE=/home/juliettej/Documents/libRationel/libRatio/build/myTest/myUnitTests -D TEST_EXECUTOR= -D TEST_WORKING_DIR=/home/juliettej/Documents/libRationel/libRatio/build/myTest -D TEST_EXTRA_ARGS= -D TEST_PROPERTIES= -D TEST_PREFIX= -D TEST_SUFFIX= -D TEST_FILTER= -D NO_PRETTY_TYPES=FALSE -D NO_PRETTY_VALUES=FALSE -D TEST_LIST=myUnitTests_TESTS -D CTEST_FILE=/home/juliettej/Documents/libRationel/libRatio/build/myTest/myUnitTests[1]_tests.cmake -D TEST_DISCOVERY_TIMEOUT=5 -D TEST_XML_OUTPUT_DIR= -P /usr/share/cmake/Modules/GoogleTestAddTests.cmake

# Rule to build all files generated by this target.
myTest/CMakeFiles/myUnitTests.dir/build: myTest/myUnitTests
.PHONY : myTest/CMakeFiles/myUnitTests.dir/build

myTest/CMakeFiles/myUnitTests.dir/clean:
	cd /home/juliettej/Documents/libRationel/libRatio/build/myTest && $(CMAKE_COMMAND) -P CMakeFiles/myUnitTests.dir/cmake_clean.cmake
.PHONY : myTest/CMakeFiles/myUnitTests.dir/clean

myTest/CMakeFiles/myUnitTests.dir/depend:
	cd /home/juliettej/Documents/libRationel/libRatio/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/juliettej/Documents/libRationel/libRatio /home/juliettej/Documents/libRationel/libRatio/myTest /home/juliettej/Documents/libRationel/libRatio/build /home/juliettej/Documents/libRationel/libRatio/build/myTest /home/juliettej/Documents/libRationel/libRatio/build/myTest/CMakeFiles/myUnitTests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : myTest/CMakeFiles/myUnitTests.dir/depend

