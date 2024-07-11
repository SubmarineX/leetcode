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
 * A permutation of an array of integers is an arrangement of its members into a
 * sequence or linear order.
 *
 * - For example, for arr = [1,2,3], the following are all the permutations of
 * arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
 *
 * The next permutation of an array of integers is the next lexicographically
 * greater permutation of its integer. More formally, if all the permutations of
 * the array are sorted in one container according to their lexicographical
 * order, then the next permutation of that array is the permutation that
 * follows it in the sorted container. If such arrangement is not possible, the
 * array must be rearranged as the lowest possible order (i.e., sorted in
 * ascending order).
 *
 * - For example, the next permutation of arr = [1,2,3] is [1,3,2].
 * - Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
 * - While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does
 * not have a lexicographical larger rearrangement.
 *
 * Given an array of integers nums, find the next permutation of nums.
 *
 * The replacement must be in place and use only constant extra memory.
 */

class Solution {
 public:
  void nextPermutation(vector<int>& nums) {
    // 1
    if (nums.size() == 1) return;
    int left = nums.size() - 1;
    while (left >= 1 && nums[left - 1] >= nums[left]) --left;
    if (left == 0) {
      // 4,3,2,1
      sort(nums.begin(), nums.end());
      return;
    }
    // left right
    //   |<->|
    // 3,4,2,1
    sort(nums.begin() + left, nums.end());
    for (int i = left; i < nums.size(); ++i) {
      // find the first num bigger than [left-1] and swap
      if (nums[i] > nums[left - 1]) {
        swap(nums[i], nums[left - 1]);
        break;
      }
    }
  }

  void nextPermutation(vector<int>& nums) {
    if (nums.size() == 1) return;
    int left = nums.size() - 1;
    while (left >= 1 && nums[left - 1] >= nums[left]) --left;
    if (left == 0) {
      reverse(nums.begin(), nums.end());  // replace sort with reverse
      return;
    }
    reverse(nums.begin() + left, nums.end());
    for (int i = left; i < nums.size(); ++i) {
      if (nums[i] > nums[left - 1]) {
        swap(nums[i], nums[left - 1]);
        break;
      }
    }
  }
};

// 1,2,3,4
//     i,j, [i] < [j], 交换 [i] [j]
// 1,2,4,3
//     i,j, [i] > [j], 找出最小的比 [i-1] 大的 [k]，交换 [i-1] [k]，重新排序 i - j
// 1,3,2,4
// 1,3,4,2
// 1,4,2,3
// 1,4,3,2
//   i,  j,
// 2,1,3,4
// 2,1,4,3
// 2,3,1,4
// 2,3,4,1
// 2,4,1,3
// 2,4,3,1
// 3,1,2,4
