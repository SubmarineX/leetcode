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
 * You are given a 0-indexed integer array nums.
 *
 * Return the maximum value over all triplets of indices (i, j, k) such that i <
 * j < k. If all such triplets have a negative value, return 0.
 *
 * The value of a triplet of indices (i, j, k) is equal to (nums[i] - nums[j]) *
 * nums[k].
 *
 * Constraints:
 *
 * - 3 <= nums.length <= 100
 * - 1 <= nums[i] <= 10^6
 */

class Solution {
 public:
  long long maximumTripletValue(vector<int>& nums) {
    long long res = 0;
    for (int i = 0; i + 2 < nums.size(); ++i) {
      for (int j = i + 1; j + 1 < nums.size(); ++j) {
        if (nums[i] <= nums[j]) continue;
        long long v1 = nums[i] - nums[j];
        int max = nums.back();
        for (int k = j + 1; k < nums.size(); ++k) {
          if (max < nums[k]) {
            max = nums[k];
          }
        }
        long long v2 = v1 * max;
        if (res < v2) {
          res = v2;
        }
      }
    }
    return res;
  }
};
