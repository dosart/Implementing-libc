###################################################################################################
##
##      Information about the project
##
###################################################################################################

cmake_minimum_required(VERSION 3.8)
project(implementing_libc VERSION 0.1 LANGUAGES C)

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

###################################################################################################
##
##      Project options
##
###################################################################################################

include_directories(include tests)
set(SOURCES
        src/main.c
        src/string.c
        tests/tests.c src/memory.c)
set(HEADERS
        include/string.h
        tests/tests.h include/memory.h)
add_executable(implementing_libc ${SOURCES} ${HEADERS})

include (CTest)
add_test(valgrind_test implementing_libc)
