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
 * You are given a 0-indexed array of positive integers nums.
 *
 * A subarray of nums is called incremovable if nums becomes strictly increasing
 * on removing the subarray. For example, the subarray [3, 4] is an incremovable
 * subarray of [5, 3, 4, 6, 7] because removing this subarray changes the array
 * [5, 3, 4, 6, 7] to [5, 6, 7] which is strictly increasing.
 *
 * Return the total number of incremovable subarrays of nums.
 *
 * Note that an empty array is considered strictly increasing.
 *
 * A subarray is a contiguous non-empty sequence of elements within an array.
 */

class Solution {
 public:
  int incremovableSubarrayCount(vector<int>& nums) {
    int res = 0;
    for (int left = 0; left < nums.size(); ++left) {
      if (left >= 2 && nums[left - 2] >= nums[left - 1]) break;
      bool found{false};
      for (int i = nums.size() - 1; i - 1 > left; --i) {
        if (nums[i - 1] >= nums[i] ||
            (left > 0 && nums[left - 1] >= nums[i - 1])) {
          // [[..., ]left, ..., i-1, i] or [[..., ]left-1, left, ..., i-1, i]
          // [                    6, 5]    [            7,              6,  ]
          found = true;
          if (left > 0 && nums[left - 1] >= nums[i]) {
            // [[..., ]left-1, left, ..., i-1, i]
            // [            7,                 5]
            res += nums.size() - i;
          } else {
            res += nums.size() - (i - 1);
          }
          break;
        }
      }
      if (!found) {
        if (nums.size() - left == 2 && left > 0 &&
            nums[left - 1] >= nums[left + 1]) {
              // [left-1, left, left+1]
              // [     7,            6]
          res += nums.size() - left - 1;
        } else {
          res += nums.size() - left;
        }
      }
    }
    return res;
  }
};

int main(int argc, char** argv) {
#if false
  vector<int> nums{1, 2};
  vector<int> nums{2, 1, 1, 4};
  vector<int> nums{1, 2, 3, 4};  // 10
  vector<int> nums{8, 7, 6, 6};  // 3
#else
  vector<int> nums{3, 7, 2};  // 4
#endif
  Solution solution;
  auto res = solution.incremovableSubarrayCount(nums);
  cout << "res '" << res << "'" << endl;
  return 0;
}
