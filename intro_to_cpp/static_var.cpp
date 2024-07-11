#include <iostream>


void test()
{
  static int t = 0;

  std::cout << t << std::endl;
  if(!t)
  {
    t = 1;
  }
}


int main()
{
  test();
  test();
  test();
  test();
  return 0;
}
