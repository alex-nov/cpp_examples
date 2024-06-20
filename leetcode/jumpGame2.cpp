#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
  int jump(vector<int> &nums)
  {
    int sz = nums.size() - 1;
    for (int i = 1; i < sz; ++i)
    {
      nums[i] = std::max(nums[i] + i, nums[i - 1]);
    }
    print(nums);

    int maxIdx = 0;
    int count = 0;

    while (maxIdx < sz)
    {
      ++count;
      maxIdx = nums[maxIdx];
      std::cout << maxIdx << "\n";
    }

    return count;
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
  vector<int> nums1{2, 3, 1, 1, 4};
  vector<int> nums2{2, 3, 0, 1, 4};
  vector<int> nums3{1, 2, 0, 1};
  vector<int> nums4{1, 2, 3};
  Solution n;

  n.print(nums1);
  int cn = n.jump(nums1);
  std::cout << "count = " << cn << "\n";

  n.print(nums2);
  cn = n.jump(nums2);
  std::cout << "count = " << cn << "\n";

  n.print(nums3);
  cn = n.jump(nums3);
  std::cout << "count = " << cn << "\n";

  n.print(nums4);
  cn = n.jump(nums4);
  std::cout << "count = " << cn << "\n";

  vector<int> nums5{0};
  n.print(nums5);
  cn = n.jump(nums5);
  std::cout << "count = " << cn << "\n";

  return 0;
}
