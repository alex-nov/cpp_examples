#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
  int hIndex(vector<int> &citations)
  {
    int sum = 0;
    for (int i = 0; i < citations.size(); ++i)
    {
      sum += citations[i];
    }
    return sum / citations.size();
  }
  void print(vector<int> &nums)
  {
    for (auto &a : nums)
      cout << a << " ";
    cout << std::endl;
  }
};

int main()
{
  Solution n;

  vector<int> nums1{3, 0, 6, 1, 5};
  n.print(nums1);
  int cn = n.hIndex(nums1);
  std::cout << "index = " << cn << "\n";

  vector<int> nums2{1, 3, 1};
  n.print(nums2);
  cn = n.hIndex(nums2);
  std::cout << "index = " << cn << "\n";

  return 0;
}
