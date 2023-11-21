#include "my_string_lib/my_string.hpp"

#include <iostream>

int main()
{
  using myspace::MyString;
  std::cout << "string tests" << std::endl;
  MyString string1;
  MyString string2( 'x', 10 );
  MyString string3( string2 );
  MyString string4{'a', 'b', 'c', 'd', 'e'};

  MyString string5 = string4;
  string5 = string2;
  return 0;
}
