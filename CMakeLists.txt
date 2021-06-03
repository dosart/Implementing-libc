cmake_minimum_required(VERSION 3.19)
project(Implementing_libc C)

include_directories(include)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror -Wshadow -Wdouble-promotion -pedantic-errors")

add_executable(Implementing_libc main.c)