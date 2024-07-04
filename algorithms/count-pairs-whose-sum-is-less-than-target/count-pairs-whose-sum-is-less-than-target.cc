#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

/*
Given a 0-indexed integer array nums of length n and an integer target, return
the number of pairs (i, j) where 0 <= i < j < n and nums[i] + nums[j] < target.
*/

class Solution {
 public:
  int countPairs(vector<int>& nums, int target) {
    int res{0};
    for (int i{0}; i < nums.size(); ++i)
      for (int j{i + 1}; j < nums.size(); ++j)
        if (nums[i] + nums[j] < target) ++res;
    return res;
  }
};
