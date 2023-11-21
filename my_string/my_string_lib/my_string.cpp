#include "my_string.hpp"

#include <iostream>
#include <cstring>
#include <algorithm>

namespace myspace
{

MyString::MyString() 
    : size( 0 )
    , capacity( default_capacity )
    , data( new char[ capacity ] )
{
  //TODO make debug output under ifdef
  std::cout << "MyString created" << std::endl;
}

MyString::MyString( const char & base, size_t size )
    : size( size )
    , capacity( size )
    , data( new char[ capacity ] )
{
  std::fill( data, data + size, base );
  //TODO make debug output under ifdef
  std::cout << "MyString created from base char: " << this->data << std::endl;
}

MyString::MyString( MyString& string )
    : size( string.size )
    , capacity( string.capacity )
    , data( new char[ string.capacity ] )
{
  strncpy( this->data, string.data, sizeof(this->data ) );
  //TODO make debug output under ifdef
  std::cout << "MyString created from another MyString: " << this->data << std::endl;
}

MyString::MyString( std::initializer_list< char > lst )
    : size( lst.size() )
    , capacity( lst.size() )
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
  swap( this->size,     other.size );
  swap( this->capacity, other.capacity );
  swap( this->data,     other.data );
}

//this->capacity<size ? size : this->capacity
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