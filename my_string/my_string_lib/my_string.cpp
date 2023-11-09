#include "my_string.hpp"

#include <iostream>
#include <cstring>

namespace myspace
{

MyString::MyString() 
  : size( 0 )
  , capacity( default_capacity )
  , data( new char[capacity] )
{
  //TODO make debug output
  std::cout << "MyString created" << std::endl;
}

MyString::MyString( char * base, size_t size )
  : size( size )
  , capacity( size )
  , data( new char[ capacity ] )
{
  strncpy( this->data, base, sizeof(this->data ) );
  //TODO make debug output
  std::cout << "MyString created from base char: " << this->data << std::endl;
}

MyString::MyString( MyString& string )
  : size( string.size )
  , capacity( string.capacity )
  , data( new char[ string.capacity ] )
{
  strncpy( this->data, string.data, sizeof(this->data ) );
  //TODO make debug output
  std::cout << "MyString created from another MyString: " << this->data << std::endl;
}

void MyString::Swap(MyString& other) throw()
{
  using std::swap; // enable ADL, defaulting to std::swap
  swap(this->size,     other.size);
  swap(this->capacity, other.capacity);
  swap(this->data,     other.data);
}

//this->capacity<size ? size : this->capacity
MyString& MyString::operator=( MyString copy )
{
  this->Swap( copy );
  //TODO make debug output
  std::cout << "MyString operator= from MyString: " << this->data << std::endl;
}

MyString::~MyString()
{
  delete[] data;
  std::cout << "MyString deleted" << std::endl;
}

}