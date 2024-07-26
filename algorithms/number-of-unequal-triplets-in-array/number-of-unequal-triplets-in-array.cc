#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

/*
 * You are given a 0-indexed array of positive integers nums. Find the number of
 * triplets (i, j, k) that meet the following conditions:
 *
 * - 0 <= i < j < k < nums.length
 * - nums[i], nums[j], and nums[k] are pairwise distinct.
 *   - In other words, nums[i] != nums[j], nums[i] != nums[k], and nums[j] !=
 * nums[k].
 *
 * Return the number of triplets that meet the conditions.
 *
 * Constraints:
 *
 * - 3 <= nums.length <= 100
 * - 1 <= nums[i] <= 1000
 */

class Solution {
 public:
  int unequalTriplets(vector<int>& nums) {
    int count = 0;
    for (int i = 0; i + 2 < nums.size(); ++i) {
      for (int j = i + 1; j + 1 < nums.size(); ++j) {
        if (nums[i] == nums[j]) continue;
        for (int k = j + 1; k < nums.size(); ++k) {
          if (nums[i] == nums[k] || nums[j] == nums[k]) continue;
          count += 1;
        }
      }
    }
    return count;
  }

  int unequalTriplets(vector<int>& nums) {
    // TODO: O(n^2)
  }

  int unequalTriplets(vector<int>& nums) {
    // TODO: O(n)
  }
};
