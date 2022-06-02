
#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

using std::vector;

// Given an integer array nums, return all the triplets
// [nums[i], nums[j], nums[k]] such that i != j, i != k,
// and j != k, and nums[i] + nums[j] + nums[k] == 0.

// Notice that the solution set must not contain duplicate triplets.

// Example 1:

// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
// Example 2:

// Input: nums = []
// Output: []
// Example 3:

// Input: nums = [0]
// Output: []

class Solution {
private:
  bool __in_t(const vector<vector<int>> &a, const vector<int> &x) {
    for (const auto &y : a) {
      if (y[0] == x[0] && y[1] == x[1] && y[2] == x[2])
        return true;
    }
    return false;
  }

public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    if (nums.size() < 3)
      return {};
    vector<vector<int>> ans{};
    std::sort(nums.begin(), nums.end());
    for (auto i = nums.begin(); i != nums.end(); i++) {
      for (auto j = nums.end() - 1; j != i; j--) {
          
      }
    }
    return ans;
  }
};
