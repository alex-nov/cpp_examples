#pragma once

#include <cstddef>

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
  MyString(char * base, size_t size);
  MyString(MyString& string);

  MyString& operator=(MyString string);

  ~MyString();
};

}