#include <vector>
#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
    unordered_map<char, int> p2i;
    unordered_map<string, int> w2i;
    istringstream in(str);
    int i = 0, n = pattern.size();
    for ( string word; in >> word; ++i )
    {
        if ( i == n || p2i[pattern[i]] != w2i[word] )
            return false;
        p2i[pattern[i]] = w2i[word] = i + 1;
    }
    return i == n;
  }
};


int main()
{
  string pattern = "abba";
  string s = "dog cat cat dog";
  Solution n;
  auto res = n.wordPattern( pattern, s );
  cout << "res = " << std::to_string( res ) << std::endl;

  res = n.wordPattern( "abba", "dog cat cat fish" );
  cout << "res = " << std::to_string( res ) << std::endl;

  res = n.wordPattern( "aaaa", "dog cat cat dog" );
  cout << "res = " << std::to_string( res ) << std::endl;

  res = n.wordPattern( "abba", "dog dog dog dog" );
  cout << "res = " << std::to_string( res ) << std::endl;

  res = n.wordPattern( "abba", "b a a b" );
  cout << "res = " << std::to_string( res ) << std::endl;

  return 0;
}

