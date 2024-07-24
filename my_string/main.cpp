#include <iostream>
#include <gtest/gtest.h>
#include "my_string_lib/my_string.hpp"

int main()
{
  testing::InitGoogleTest();
  std::cout << "string tests result:" << std::endl;
  std::cout << RUN_ALL_TESTS();

  myspace::MyString str( "test str\n" );
  std::cout << str;

  return 0;
}
