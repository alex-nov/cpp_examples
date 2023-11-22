#pragma once

#include <cstddef>
#include <initializer_list>

namespace myspace
{

const size_t default_capacity = 10;

class MyString
{
private:
  size_t sz;
  size_t cap;
  char * data;

  void Swap(MyString& other) throw();
public:
  MyString();
  MyString( const char & base, size_t size );
  MyString( MyString& string );
  MyString( std::initializer_list<char> lst);

  MyString& operator=( MyString string );

  inline size_t size()      { return sz; }
  inline size_t capacity()  { return cap; }
  inline bool empty()       { return static_cast< bool >( sz ); }
  inline const char * c_str()       { return data; }

  ~MyString();
};

}