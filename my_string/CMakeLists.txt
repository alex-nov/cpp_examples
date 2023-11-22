cmake_minimum_required(VERSION 3.19)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(APPNAME "my_string_project")
set(AP_VERSION 0.1.0)

project(${APPNAME}
        VERSION ${AP_VERSION}
        DESCRIPTION "String example C++ built with CMake and googletest"
        LANGUAGES CXX)

add_subdirectory(tests)

enable_testing()

add_executable(${APPNAME} 
  main.cpp
  my_string_lib/my_string.cpp
  )
