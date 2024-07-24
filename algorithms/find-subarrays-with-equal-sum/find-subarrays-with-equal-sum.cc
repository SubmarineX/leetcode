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
 * Given a 0-indexed integer array nums, determine whether there exist two
 * subarrays of length 2 with equal sum. Note that the two subarrays must begin
 * at different indices.
 *
 * Return true if these subarrays exist, and false otherwise.
 *
 * A subarray is a contiguous non-empty sequence of elements within an array.
 *
 * Constraints:
 *
 * - 2 <= nums.length <= 1000
 * - -109 <= nums[i] <= 109
 */

class Solution {
 public:
  bool findSubarrays(vector<int>& nums) {
    if (nums.size() <= 2) return false;
    std::unordered_set<std::int32_t> sums;
    for (std::size_t i = 0; i + 1 < nums.size(); ++i) {
      std::int32_t sum = nums[i] + nums[i + 1];
      if (sums.find(sum) != sums.end()) return true;
      sums.insert(sum);
    }
    return false;
  }
};
