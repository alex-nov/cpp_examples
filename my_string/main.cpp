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
/* TODO
  std::cout << "string tests compare1" << string1 == string2 << std::endl;
  std::cout << "string tests compare2" << string2 > string3 << std::endl;
  std::cout << "string tests compare1" << string3 < string4 << std::endl;
*/
  MyString string6( "Hello " );
  MyString string7( "world!" );

  string6.add( string7 );

  return 0;
}
