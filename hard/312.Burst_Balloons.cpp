// You are given n balloons, indexed from 0 to n - 1.
// Each balloon is painted with a number on it represented by an array nums.
// You are asked to burst all the balloons.

// If you burst the ith balloon, you will get
// nums[i - 1] * nums[i] * nums[i + 1] coins.
// If i - 1 or i + 1 goes out of bounds of the array,
// then treat it as if there is a balloon with a 1 painted on it.

// Return the maximum coins you can collect by bursting the balloons wisely.

#include <algorithm>
#include <iostream>
#include <vector>
using std::vector;

class Solution {
public:
  int maxCoins(vector<int> &nums, int first = 1, int last = 1) {
    if (nums.empty()) return 0;
    if (nums.size() == 1)
      return first * last * nums.front();
    vector<int> ans;
    for (auto i = nums.begin(); i != nums.end(); ++i) {
      int pro = first * *i * last;
      vector<int> left(nums.begin(), i);
      vector<int> right(i+1, nums.end());
      ans.push_back(pro + maxCoins(left, first, *i) +
                    maxCoins(right, *i, last));
    }
    return *max_element(std::begin(ans), std::end(ans));
  }
};


// Example 1:

// Input: nums = [3,1,5,8]
// Output: 167
// Explanation:
// nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
// coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
// Example 2:

// Input: nums = [1,5]
// Output: 10

// Constraints:

// n == nums.length
// 1 <= n <= 300
// 0 <= nums[i] <= 100