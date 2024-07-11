#include "my_string.hpp"

#include <iostream>
#include <cstring>
#include <algorithm>

namespace myspace
{

MyString::MyString()
    : sz( 0 )
    , cap( default_capacity )
    , data( new char[ cap ] )
{
  //TODO make debug output under ifdef
  std::cout << "MyString created" << std::endl;
}

MyString::MyString( const char & base, size_t size )
    : sz( size )
    , cap( size )
    , data( new char[ cap ] )
{
  std::fill( data, data + sz, base );
  //TODO make debug output under ifdef
  std::cout << "MyString created from base char and size: " << this->data << std::endl;
}

MyString::MyString( const char * base )
    : sz( sizeof( base ) )
    , cap( sz )
    , data( new char[ cap ] )
{
  memcpy(data, base, sz);
  //TODO make debug output under ifdef
  std::cout << "MyString created from const char*: " << this->data << std::endl;
}

MyString::MyString( MyString& string )
    : sz( string.sz )
    , cap( string.cap )
    , data( new char[ string.cap ] )
{
  strncpy( this->data, string.data, string.sz );
  //TODO make debug output under ifdef
  std::cout << "MyString created from another MyString: " << this->data << std::endl;
}

MyString::MyString( std::initializer_list< char > lst )
    : sz( lst.size() )
    , cap( lst.size() )
    , data( new char[ lst.size() ] )
{
  size_t i = 0;
  for( auto ch : lst )
  {
    data[ i++ ] = ch;
  }
  // или std::copy(lst.begin(), lst.edn(), data );

  //TODO make debug output under ifdef
  std::cout << "MyString created from another initializer_list: " << this->data << std::endl;
}

void MyString::Swap( MyString& other ) throw()
{
  using std::swap; // enable ADL, defaulting to std::swap
  swap( this->sz,     other.sz );
  swap( this->cap, other.cap );
  swap( this->data,     other.data );
}

MyString& MyString::add(MyString& other)
{
  char* new_data = new char[cap + other.cap];
  memcpy(new_data, data, sz);
  memcpy(new_data + sz, other.data, other.sz);
  delete[] data;
  data = new_data;

  sz += other.sz;
  cap += other.cap;

  //TODO make debug output under ifdef
  std::cout << "MyString add: " << this->data << std::endl;
  return *this;
}

//this->cap<sz ? sz : this->cap
MyString& MyString::operator=( MyString copy )
{
  this->Swap( copy );
  //TODO make debug output under ifdef
  std::cout << "MyString operator= from MyString: " << this->data << std::endl;
  return *this;
}

MyString::~MyString()
{
  delete[] data;
  //TODO make debug output under ifdef
  std::cout << "MyString deleted" << std::endl;
}

}