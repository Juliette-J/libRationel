cmake_minimum_required(VERSION 3.13)

# give a name to the project
project(examples)

# find Rational
# if build as standalone project, find the lib by yourself ...
# if build transitively 

add_executable(examples src/main.cpp)                # file to compile and name of the app
target_link_libraries(examples PRIVATE Rational)      # lib dependency

# compilation flags
target_compile_features(examples PRIVATE cxx_std_20) # use at least c++ 20
if (MSVC)
    target_compile_options(examples PRIVATE /W3)
else()
    target_compile_options(examples PRIVATE -Wall -Wextra -Wpedantic -pedantic-errors)
endif()