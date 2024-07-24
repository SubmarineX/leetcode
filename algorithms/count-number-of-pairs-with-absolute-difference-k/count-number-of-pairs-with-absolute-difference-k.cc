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
 * Given an integer array nums and an integer k, return the number of pairs (i,
 * j) where i < j such that |nums[i] - nums[j]| == k.
 *
 * The value of |x| is defined as:
 *
 * - x if x >= 0.
 * - -x if x < 0.
 *
 * Constraints:
 *
 * - 1 <= nums.length <= 200
 * - 1 <= nums[i] <= 100
 * - 1 <= k <= 99
 */

class Solution {
 public:
  int countKDifference(vector<int>& nums, int k) {
    int count = 0;
    for (int i = 0; i < nums.size(); ++i) {
      for (int j = i + 1; j < nums.size(); ++j) {
        if (std::abs(nums[i] - nums[j]) == k) ++count;
      }
    }
    return count;
  }
};
