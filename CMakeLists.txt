###################################################################################################
##
##      Information about the project
##
###################################################################################################

cmake_minimum_required(VERSION 3.16)

set(PROJECT_NAME libc)
project(${PROJECT_NAME} VERSION 0.0.1 LANGUAGES C)

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
        tests/tests.c src/memory.c src/garbage_collector.c)
set(HEADERS
        include/string.h
        tests/tests.h include/memory.h include/garbage_collector.h)
        
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

include (CTest)
add_test(valgrind_test ${PROJECT_NAME})
