#include <gtest/gtest.h>
#include "my_string.hpp"

#include <iostream>

//ctest --verbose

TEST(my_string_tests, empty_string)
{
    myspace::MyString str;
    EXPECT_TRUE( str.empty() );
    EXPECT_EQ( 0, str.size() );
}

TEST(my_string_tests, init_multiply_symbol)
{
    myspace::MyString str( 'x', 5 );
    EXPECT_FALSE( str.empty() );
    EXPECT_EQ( str.size(), 5 );
    EXPECT_EQ( "xxxxx", str.c_str() ) << "MyString.data is wrong";
}

TEST(my_string_tests, init_from_const_str)
{
    myspace::MyString str( "xxxxx" );
    EXPECT_FALSE( str.empty() );
    EXPECT_EQ( str.size(), 5 );
    EXPECT_EQ( "xxxxx", str.c_str() );
}

TEST(my_string_tests, init_from_initializer_list)
{
    myspace::MyString str{'a', 'b', 'c', 'd', 'e'};
    EXPECT_FALSE( str.empty() );
    EXPECT_EQ( str.size(), 5 );
    EXPECT_EQ( "abcde", str.c_str() );
}

TEST(my_string_tests, init_from_another_str)
{
    myspace::MyString str1( 'x', 5 );
    myspace::MyString str2( str1 );
    EXPECT_FALSE( str1.empty() );
    EXPECT_FALSE( str2.empty() );
    EXPECT_EQ( "xxxxx", str2.c_str() );
    //TODO : EXPECT_EQ( str1, str2 );
}

TEST(my_string_tests, add_str)
{
    myspace::MyString str1( "Hello " );
    myspace::MyString str2( "world!" );
    ASSERT_FALSE( str1.empty() );
    ASSERT_FALSE( str2.empty() );
    str1.add( str2 );
    EXPECT_EQ( "Hello world!", str1.c_str() );
}
