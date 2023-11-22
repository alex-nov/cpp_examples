cmake_minimum_required(VERSION 3.19)

set(APPNAME "my_string_tests")

project(${APPNAME}
        VERSION ${AP_VERSION}
        DESCRIPTION "String example C++ built with CMake and googletest"
        LANGUAGES CXX)

add_subdirectory(googletest)

# TODO: add tests
#add_executable(${APPNAME} 
#  )
