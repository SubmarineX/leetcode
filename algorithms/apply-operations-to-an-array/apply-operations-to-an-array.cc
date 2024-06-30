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
 * You are given a 0-indexed array nums of size n consisting of non-negative
 * integers.
 *
 * You need to apply n - 1 operations to this array where, in the ith operation
 * (0-indexed), you will apply the following on the ith element of nums:
 *
 * - If nums[i] == nums[i + 1], then multiply nums[i] by 2 and set nums[i + 1]
 * to 0. Otherwise, you skip this operation.
 *
 * After performing all the operations, shift all the 0's to the end of the
 * array.
 *
 * - For example, the array [1,0,2,0,0,1] after shifting all its 0's to the end,
 * is [1,2,1,0,0,0].
 *
 * Return the resulting array.
 *
 * Note that the operations are applied sequentially, not all at once.
 */

class Solution {
 public:
  vector<int> applyOperations(vector<int>& nums) {
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i - 1] == nums[i]) {
        nums[i - 1] *= 2;
        nums[i] = 0;
      }
    }
    int i = 0;
    int j = 0;
    while (i < nums.size() && j < nums.size()) {
      while (i < nums.size() && nums[i]) {  // find 0
        ++i;
      }
      if (i >= nums.size()) break;  // note bound
      if (j <= i) {
        j = i + 1;
      }
      while (j < nums.size() && !nums[j]) {  // find !0
        ++j;
      }
      if (j >= nums.size()) break;  // note bound
      swap(nums[i++], nums[j++]);
    }
    return nums;
  }

  // ...

  // See also 283. Move Zeroes
  vector<int> applyOperations(vector<int>& nums) {
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i - 1] == nums[i]) {
        nums[i - 1] *= 2;
        nums[i] = 0;
      }
    }

    // `i` always points to the first element or 0
    for (int i = 0, j = 0; j < nums.size(); j++) {
      if (nums[j]) {
        swap(nums[j], nums[i]);
        ++i;
      }
    }
    return nums;
  }
};
