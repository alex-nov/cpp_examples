cmake_minimum_required(VERSION 3.19)

set(LIBNAME "my_string_t")
set(APPNAME "my_string_t")

project(${APPNAME}
        VERSION ${AP_VERSION}
        DESCRIPTION "String example C++ built with CMake and googletest"
        LANGUAGES CXX)

add_subdirectory(googletest)

include_directories( ${PROJECT_SOURCE_DIR}/../my_string_lib)

enable_testing()

add_executable(${APPNAME}
        my_string_tests/test.cpp
        ${PROJECT_SOURCE_DIR}/../my_string_lib/my_string.cpp)

target_link_libraries(
        ${APPNAME}
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(my_string_t)

message(${PROJECT_SOURCE_DIR})
# TODO: add tests
#add_executable(${APPNAME}
#  )
