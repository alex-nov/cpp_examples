#include <gtest/gtest.h>
#include "my_string.hpp"

#include <iostream>

//ctest --verbose

using myspace::MyString;

TEST(my_string_tests, empty_string)
{
    MyString str;
    EXPECT_TRUE( str.empty() );
    EXPECT_EQ( 0, str.size() );
}

TEST(my_string_tests, init_multiply_symbol)
{
    MyString str( 'x', 5 );
    EXPECT_FALSE( str.empty() );
    EXPECT_EQ( str.size(), 5 );
    EXPECT_TRUE( !strncmp( "xxxxx", str.c_str(), str.size() ) );
}

TEST(my_string_tests, init_from_const_str)
{
    MyString str( "xxxxx" );
    EXPECT_FALSE( str.empty() );
    EXPECT_EQ( str.size(), 5 );
    EXPECT_TRUE( !strncmp( "xxxxx", str.c_str(), str.size() ) );
}

TEST(my_string_tests, init_from_initializer_list)
{
    MyString str{'a', 'b', 'c', 'd', 'e'};
    EXPECT_FALSE( str.empty() );
    EXPECT_EQ( str.size(), 5 );
    EXPECT_TRUE( !strncmp( "abcde", str.c_str(), str.size() ) );
}

TEST(my_string_tests, init_from_another_str)
{
    MyString str1( 'x', 5 );
    MyString str2( str1 );
    EXPECT_FALSE( str1.empty() );
    EXPECT_FALSE( str2.empty() );
    EXPECT_TRUE( !strncmp( "xxxxx", str2.c_str(), str2.size() ) );
    EXPECT_TRUE( !strncmp( str1.c_str(), str2.c_str(), str2.size() ) );
    EXPECT_EQ( str1, str2 );
}

TEST(my_string_tests, add_str)
{
    MyString str1( "Hello " );
    MyString str2( "world!" );
    ASSERT_FALSE( str1.empty() );
    ASSERT_FALSE( str2.empty() );
    str1.add( str2 );
    EXPECT_TRUE( !strncmp( "Hello world!", str1.c_str(), str1.size() ) );
}

TEST(my_string_tests, equality_operators)
{
    const MyString str1( "hello world!" );
    const MyString str2( "hello world!" );
    const MyString str3( "not hello" );

    ASSERT_FALSE( str1.empty() );
    ASSERT_FALSE( str2.empty() );
    ASSERT_FALSE( str3.empty() );

    EXPECT_TRUE( str1 == str2 );
    EXPECT_FALSE( str1 == str3 );
    EXPECT_TRUE( str1 != str3 );
    EXPECT_FALSE( str1 != str2 );
}

TEST(my_string_tests, less_more_operators)
{
    MyString str1( 'x', 5 );
    MyString str2( 'x', 6 );

    ASSERT_FALSE( str1.empty() );
    ASSERT_FALSE( str2.empty() );

    EXPECT_TRUE( str1 < str2 );
    EXPECT_FALSE( str2 < str1 );
    EXPECT_TRUE( str2 > str1 );
    EXPECT_FALSE( str1 > str2 );
}
