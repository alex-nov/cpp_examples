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
    , cap( size + 1 )
    , data( new char[ cap ] )
{
  memset( data, base, size);
  data[ sz ] = '\0';
  //TODO make debug output under ifdef
  std::cout << "MyString created from base char and size: " << this->data << std::endl;
}

MyString::MyString( const char * base )
    : sz( strlen( base ) )
    , cap( sz + 1 )
    , data( new char[ cap ] )
{
  memcpy(data, base, sz);
  data[ sz ] = '\0';
  //TODO make debug output under ifdef
  std::cout << "MyString created from const char*: " << this->data << std::endl;
}

MyString::MyString( const MyString & string )
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
    , cap( lst.size() + 1 )
    , data( new char[ lst.size() ] )
{
  size_t i = 0;
  for( auto ch : lst )
  {
    data[ i++ ] = ch;
  }
  data[ sz ] = '\0';
  // или std::copy(lst.begin(), lst.edn(), data );

  //TODO make debug output under ifdef
  std::cout << "MyString created from another initializer_list: " << this->data << std::endl;
}

void MyString::Swap( MyString& other ) throw()
{
  using std::swap; // enable ADL, defaulting to std::swap
  swap( this->sz,   other.sz );
  swap( this->cap,  other.cap );
  swap( this->data, other.data );
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

  data[ sz + other.sz ] = '\0';

  //TODO make debug output under ifdef
  std::cout << "MyString add: " << this->data << std::endl;
  return *this;
}

bool MyString::operator==( const MyString & str ) const
{
  std::cout << "MyString operator==" << std::endl;
  if( str.sz != sz ) return false;
  return !strncmp( data, str.data, sz );
}

bool MyString::operator!=( const MyString & string ) const
{
  std::cout << "MyString operator!=" << std::endl;
  return !( this->operator==( string ) );
}

bool MyString::operator<( const MyString & string ) const
{
  std::cout << "MyString operator<" << std::endl;
  if( sz < string.sz ) return true;
  else if( string.sz < sz ) return false;

  for( size_t i = 0; i < sz; ++i )
  {
    if( static_cast<int>( data[sz] ) > static_cast<int>( string.data[sz] ) ) return false;
  }

  return true;
}

bool MyString::operator>( const MyString & string ) const
{
  std::cout << "MyString operator>" << std::endl;
  return string.sz < sz;
}

}

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