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
 * Given a 0-indexed integer array nums of length n and an integer k, return the
 * number of pairs (i, j) where 0 <= i < j < n, such that nums[i] == nums[j] and
 * (i * j) is divisible by k.
 *
 * Constraints:
 *
 * - 1 <= nums.length <= 100
 * - 1 <= nums[i], k <= 100
 */

class Solution {
 public:
  int countPairs(vector<int>& nums, int k) {
    int count = 0;
    for (int i = 0; i + 1 < nums.size(); ++i) {
      for (int j = i + 1; j < nums.size(); ++j) {
        if (nums[i] == nums[j] && !(i * j % k)) count += 1;
      }
    }
    return count;
  }
};
