#include<vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int minChanges(int n, int k) {
        cout << n << " | " << k << endl;
        if ( n < k ) return -1; // Если невозможно сделать n равным k
        int count = 0;

        while (n != k) {
            cout << (n & 1) << " | " << (k & 1) << endl;
            if ( 0 == (n & 1) && 1 == (k & 1)) return -1;
            if ( 1 == (n & 1) && 0 == (k & 1)) ++count;

            n >>= 1;
            k >>= 1;
        }

        return count;
    }
};


int main()
{
  Solution sol;

  int rez = sol.minChanges( 13, 4 );
  cout << rez << std::endl;

  rez = sol.minChanges( 21, 21 );
  cout << rez << std::endl;

  rez = sol.minChanges( 14, 13 );
  cout << rez << std::endl;

  return 0;
}

