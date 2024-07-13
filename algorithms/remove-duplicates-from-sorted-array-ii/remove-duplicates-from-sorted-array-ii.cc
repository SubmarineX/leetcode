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
 * Given an integer array nums sorted in non-decreasing order, remove some
 * duplicates in-place such that each unique element appears at most twice. The
 * relative order of the elements should be kept the same.
 *
 * Since it is impossible to change the length of the array in some languages,
 * you must instead have the result be placed in the first part of the array
 * nums. More formally, if there are k elements after removing the duplicates,
 * then the first k elements of nums should hold the final result. It does not
 * matter what you leave beyond the first k elements.
 *
 * Return k after placing the final result in the first k slots of nums.
 *
 * Do not allocate extra space for another array. You must do this by modifying
 * the input array in-place with O(1) extra memory.
 */

class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    if (nums.size() <= 2) return nums.size();
    int i = 0;
    int count = 0;
    while (i < nums.size()) {
      if (i == 0) {
        ++count;
        ++i;
        continue;
      }
      if (nums[i] == nums[i - 1]) {
        ++count;
        if (i == nums.size() - 1 && count > 2) {
          for (int j = i - count + 3; j <= i; ++j) {
            nums[j] = 10001;
          }
        }
        ++i;
        continue;
      }
      if (nums[i] != nums[i - 1]) {
        for (int j = i - count + 2; j < i; ++j) {
          nums[j] = 10001;
        }
        count = 1;
        ++i;
      }
    }

    int left = 0;
    int right = 0;
    while (right < nums.size()) {
      if (nums[right] == 10001) {
        ++right;
        continue;
      }
      swap(nums[left++], nums[right++]);
    }
    return nums.size() - (right - left);
  }

  // https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
  // []  []  []...[]
  // l-2 l-1 l    r
  // [0, l) is index range of mofitied array
  // [l-2] == [r]: [l-2, r] are same
  // [l-2] != [r]: [l-1] maybe == [r] or not, that is allowed
  int removeDuplicates(vector<int>& nums) {
    if (nums.size() <= 2) return nums.size();
    int left = 2;
    int right = 2;
    while (right < nums.size()) {
      if (nums[left - 2] != nums[right]) {
        nums[left++] = nums[right];
      }
      ++right;
    }
    return left;
  }
};
