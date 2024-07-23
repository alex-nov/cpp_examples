#include <iostream>
#include <gtest/gtest.h>

int main()
{
  testing::InitGoogleTest();
  std::cout << "string tests result:" << std::endl;
  std::cout << RUN_ALL_TESTS();

  return 0;
}
