###################################################################################################
##
##      Information about the project
##
###################################################################################################

cmake_minimum_required(VERSION 3.16)

set(PROJECT_NAME smart_pointers)
project(${PROJECT_NAME} VERSION 1.0.0
        DESCRIPTION "simple smart pointers library"
        LANGUAGES CXX
        )

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
        -Wctor-dtor-privacy
        -Wenum-compare
        -Wfloat-equal
        -Wnon-virtual-dtor
        -Wold-style-cast
        -Woverloaded-virtual
        -Wredundant-decls
        -Wsign-conversion
        -Wsign-promo
)

###################################################################################################
##
##      Project options
##
###################################################################################################
set(SOURCES
        unique_ptr.hpp)

add_library(${PROJECT_NAME} STATIC ${SOURCES})
set_target_properties(
        ${PROJECT_NAME} PROPERTIES
        LINKER_LANGUAGE CXX
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)
       
add_executable(tests main.cpp)
set_target_properties(
        tests PROPERTIES
        LINKER_LANGUAGE CXX
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)
target_link_libraries(tests ${PROJECT_NAME})
