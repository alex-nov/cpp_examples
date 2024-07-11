cmake_minimum_required(VERSION 3.19)

set(APPNAME "my_string_project")
set(AP_VERSION 0.1.0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Werror -Wempty-body -Wredundant-move -Wno-error=deprecated-declarations -Wimplicit-fallthrough")

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
