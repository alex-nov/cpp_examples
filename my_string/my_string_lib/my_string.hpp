#pragma once

#include <cstddef>
#include <initializer_list>

namespace myspace
{

const unsigned int default_capacity = 10;

class MyString
{
private:
  unsigned int size;
  unsigned int capacity;
  char * data;

  void Swap(MyString& other) throw();
public:
  MyString();
  MyString( const char & base, size_t size );
  MyString( MyString& string );
  MyString( std::initializer_list<char> lst);

  MyString& operator=( MyString string );

  ~MyString();
};

}