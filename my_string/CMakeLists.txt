cmake_minimum_required(VERSION 3.19)

project(my_string)

set(APPNAME "string_tests")

add_executable(${APPNAME} 
  main.cpp
  my_string_lib/my_string.cpp
  )
