#pragma once

#include <cstddef>
#include <initializer_list>
#include <compare>
#include <iostream>

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

  bool operator==( const MyString & string ) const;
  bool operator!=( const MyString & string ) const;
  bool operator<( const MyString & string ) const;
  bool operator>( const MyString & string ) const;

  char & operator[]( size_t index );
  const char & operator[]( size_t index ) const;

  friend std::ostream & operator<<( std::ostream & stream, MyString & str );
  friend std::istream & operator>>( std::istream & stream, MyString & str );

  inline size_t size() const { return sz; }
  inline size_t capacity() const { return cap; }
  inline bool empty() const { return sz == 0; }
  inline const char * c_str() const { return data; }

  virtual ~MyString();
};

}