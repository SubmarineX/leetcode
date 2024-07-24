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
 * Given an array of integers nums containing n + 1 integers where each integer
 * is in the range [1, n] inclusive.
 *
 * There is only one repeated number in nums, return this repeated number.
 *
 * You must solve the problem without modifying the array nums and uses only
 * constant extra space.
 */

class Solution {
 public:
  /**
   * Floyd's Tortoise and Hare (Cycle Detection) algorithm
   * (or slow and fast pointer). This algorithm is typically used for detecting
   * cycles in a linked list but can be adapted for this problem since the
   * presence of a duplicate number implies a cycle in the "linked list" formed
   * by treating array indices as pointers.
   * [Floyd's Tortoise and Hare]
   * [Fast Slow Pointers]
   */
  int findDuplicate(vector<int>& nums) {
    int tortoise = nums[0];
    int hare = nums[0];
    while (true) {
      tortoise = nums[tortoise];
      hare = nums[nums[hare]];
      if (tortoise == hare) break;
    }

    tortoise = nums[0];
    while (tortoise != hare) {
      tortoise = nums[tortoise];
      hare = nums[hare];
    }

    return hare;
  }

  /**
   * Binary Search. The core idea of the binary search method is to utilize the
   * relationship between elements and indices in the array. By counting the
   * number of elements less than or equal to a certain value, we can
   * progressively narrow down the range that might contain the duplicate
   * number.
   * [Binary Search]
   * [Pigeonhole Principle]
   */
  int findDuplicate(vector<int>& nums) {
    int low = 1;
    int high = nums.size() - 1;

    while (low < high) {
      int mid = low + (high - low) / 2;
      int count = std::count_if(nums.begin(), nums.end(),
                                [&mid](int i) { return i <= mid; });
      if (count <= mid) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }

    return low;
  }

  /**
   * [Bit Manipulation]
   */
  int findDuplicate(vector<int>& nums) {
    // TODO: findDuplicate
  }
};
