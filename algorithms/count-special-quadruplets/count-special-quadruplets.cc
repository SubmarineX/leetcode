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
 * Given a 0-indexed integer array nums, return the number of distinct
 * quadruplets (a, b, c, d) such that:
 *
 * - nums[a] + nums[b] + nums[c] == nums[d], and
 * - a < b < c < d
 *
 * Constraints:
 *
 * - 4 <= nums.length <= 50
 * - 1 <= nums[i] <= 100
 */

class Solution {
 public:
  int countQuadruplets(vector<int>& nums) {
    int count = 0;
    for (int a = 0; a + 3 < nums.size(); ++a) {
      for (int b = a + 1; b + 2 < nums.size(); ++b) {
        for (int c = b + 1; c + 1 < nums.size(); ++c) {
          for (int d = c + 1; d < nums.size(); ++d) {
            if (nums[a] + nums[b] + nums[c] == nums[d]) count += 1;
          }
        }
      }
    }
    return count;
  }

  int countQuadruplets(vector<int>& nums) {
    // TODO: hash table
  }
};
