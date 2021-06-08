###################################################################################################
##
##      Information about the project
##
###################################################################################################


cmake_minimum_required(VERSION 3.19)
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


include_directories(include)
set(SOURCES
    main.c
    src/string.c
    tests/tests.c)
set(HEADERS
    src/weather_api.h
    src/bot.h
    src/language_support.h)
add_executable(implementing_libc ${SOURCES} ${HEADERS})
