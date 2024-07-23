#include<vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> result;
        int k,j;
        k = j = 0;
        result.reserve( nums1.size() + nums2.size() );
        for( int i = 0; i < nums1.size(); ++i )
        {
            result.emplace_back( nums1[ j ] <= nums2[ k ] ? nums1[ j++ ] : nums2[ k++ ]);
        }
        nums1.swap( result );
    }
};


int main()
{
  vector<int> nums1{1,2,3};
  vector<int> nums2{2,5,6};
  Solution n;
  n.merge(nums1, 3, nums2, 3);

  for( auto & a : nums1 )
    cout << a << " ";

  cout << std::endl;

  return 0;
}

