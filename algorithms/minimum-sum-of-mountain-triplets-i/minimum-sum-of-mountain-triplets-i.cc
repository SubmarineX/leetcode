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
 * You are given a 0-indexed array nums of integers.
 *
 * A triplet of indices (i, j, k) is a mountain if:
 *
 * - i < j < k
 * - nums[i] < nums[j] and nums[k] < nums[j]
 *
 * Return the minimum possible sum of a mountain triplet of nums. If no such
 * triplet exists, return -1.
 *
 * Constraints:
 *
 * - 3 <= nums.length <= 50
 * - 1 <= nums[i] <= 50
 */

class Solution {
 public:
  int minimumSum(vector<int>& nums) {
    int min = -1;
    if (nums.size() < 3) return -1;
    for (int i = 0; i + 2 < nums.size(); ++i) {
      for (int j = i + 1; j + 1 < nums.size(); ++j) {
        if (nums[i] >= nums[j]) break;
        for (int k = j + 1; k < nums.size(); ++k) {
          if (nums[k] >= nums[j]) continue;
          int sum = nums[i] + nums[j] + nums[k];
          if (min == -1 || min > sum) {
            min = sum;
          }
        }
      }
    }
    return min;
  }
};
