#pragma once

#include <cstddef>
#include <initializer_list>
#include <compare>

namespace myspace
{

const size_t default_capacity = 10;

class MyString
{
private:
  size_t sz;
  size_t cap;
  char * data;

  void Swap( MyString& other ) throw();
public:
  MyString();
  MyString( const char & base, size_t size );
  MyString( const char * base );
  MyString( const MyString& string );
  MyString( std::initializer_list<char> lst);

  MyString& operator=( MyString string );

  MyString& add( MyString& other) ;

  // TODO: операторы сравнения; операторы << >>
  //auto operator<=>( const MyString & other ) const = default;
  bool operator==( const MyString & string ) const;
  bool operator!=( const MyString & string ) const;
  bool operator<( const MyString & string ) const;
  bool operator>( const MyString & string ) const;

  //friend bool operator==( const MyString & string1, const MyString & string2);
  //friend bool operator<( const MyString & string1, const MyString & string2);

  inline size_t size() const { return sz; }
  inline size_t capacity() const { return cap; }
  inline bool empty() const { return sz == 0; }
  inline const char * c_str() const { return data; }

  virtual ~MyString();
};

}