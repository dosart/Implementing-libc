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

###################################################################################################
##
##      Compilation options
##
###################################################################################################

target_compile_options( ${PROJECT_NAME} PRIVATE
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
##     GoogleTest options
##
###################################################################################################

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

FetchContent_MakeAvailable(googletest)

set(TEST test)

add_executable(
  ${TEST}
  main.cpp
)

target_link_libraries(
  ${TEST}
  ${PROJECT_NAME}
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(${TEST})
