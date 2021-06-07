cmake_minimum_required(VERSION 3.19)
project(simole_std_lib VERSION 0.1 LANGUAGES C)

include_directories(include)

set(CMAKE_C_STANDARD 11)

###################################################################################################
##
##      Compilation options
##
###################################################################################################
add_compile_options(
        -Werror

        -Wall
        -Wextra
        -Wpedantic

        -Wcast-align
        -Wcast-qual

        -Wconversion
        -Wfloat-equal
        -Wredundant-decls
        -Wsign-conversion
)
add_executable(Implementing_libc main.c include/string.h src/string.c tests/tests.c tests/tests.h)