#include <algorithm>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

/*
 * Given an integer array nums, move all 0's to the end of it while maintaining
 * the relative order of the non-zero elements.
 *
 * Note that you must do this in-place without making a copy of the array.
 */

class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    int i = 0;
    int j = 0;
    while (true) {
      while (i < nums.size() && nums[i]) {  // find 0
        ++i;
      }
      if (j < i) {
        j = i + 1;
      }
      while (j < nums.size() && !nums[j]) {  // find !0
        ++j;
      }
      if (i < nums.size() && j < nums.size()) {
        nums[i] = nums[j];
        nums[j] = 0;
        ++i;
        ++j;
      } else {
        break;
      }
    }
  }

  // ...

  void moveZeroes(vector<int>& nums) {
    for (int i = 0, j = 0; j < nums.size(); j++) {
      if (nums[j]) {
        if (i != j) {
          swap(nums[j], nums[i]);
        }
        ++i;
      }
    }
  }
};
