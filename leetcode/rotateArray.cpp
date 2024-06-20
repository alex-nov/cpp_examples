#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
  void rotate(vector<int> &nums, int k)
  {
    vector<int> result(nums.size(), 0);
    k = nums.size() - k;
    for (int i = 0; i < nums.size(); ++i)
    {
      cout << (i + k) % nums.size() << "\n";
      result[i] = nums[(i + k) % nums.size()];
    }
    std::swap(nums, result);
  }
  void print(vector<int> &nums)
  {
    for (auto &a : nums)
      cout << a << " ";
    cout << std::endl
         << std::endl;
  }
};

int main()
{
  vector<int> nums1{1, 2, 3, 4, 5, 6, 7};
  vector<int> nums2{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  vector<int> nums3{1, 2, 3};
  Solution n;
  n.rotate(nums1, 3);
  n.print(nums1);
  n.rotate(nums2, 3);
  n.print(nums2);
  n.print(nums2);
  n.rotate(nums3, 4);
  n.print(nums3);
  return 0;
}
