cmake_minimum_required(VERSION 3.19)

set(APPNAME "my_string_tests")
set(AP_VERSION 0.1.0)

project(${APPNAME}
        VERSION ${AP_VERSION}
        DESCRIPTION "String example C++ built with CMake and googletest"
        LANGUAGES CXX)


enable_testing()

add_executable(${APPNAME} 
  main.cpp
  my_string_lib/my_string.cpp
  )
