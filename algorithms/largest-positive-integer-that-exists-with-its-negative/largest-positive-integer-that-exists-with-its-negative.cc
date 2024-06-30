#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

/*
 *Given an integer array nums that does not contain any zeros, find the largest
 *positive integer k such that -k also exists in the array.
 *
 *Return the positive integer k. If there is no such integer, return -1.
 */

class Solution {
 public:
  int findMaxK(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    for (int i = nums.size() - 1; i >= 0 && nums[i] > 0; --i) {
      if (binary_search(nums.begin(), nums.end(), -nums[i])) return nums[i];
    }
    return -1;
  }

  int findMaxK(vector<int>& nums) {
    unordered_set<int> us;
    for (auto&& v : nums) {
      if (v < 0) {
        us.emplace(v);
      }
    }
    int res = -1;
    for (auto&& v : nums) {
      if (v > 0 && us.find(-v) != us.end()) {
        res = max(res, v);
      }
    }
    return res;
  }
};
