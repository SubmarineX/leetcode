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
 * You are given a 0-indexed integer array nums.
 *
 * The concatenation of two numbers is the number formed by concatenating their
 * numerals.
 *
 * - For example, the concatenation of 15, 49 is 1549.
 *
 * The concatenation value of nums is initially equal to 0. Perform this
 * operation until nums becomes empty:
 *
 * - If there exists more than one number in nums, pick the first element and
 * last element in nums respectively and add the value of their concatenation to
 * the concatenation value of nums, then delete the first and last element from
 * nums.
 * - If one element exists, add its value to the concatenation value of nums,
 * then delete it.
 *
 * Return the concatenation value of the nums.
 */

class Solution {
 public:
  long long findTheArrayConcVal(vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;
    long long res = 0;  // must not use int
    while (left < right) {
      res +=
          stoll(std::to_string(nums[left++]) + std::to_string(nums[right--]));
    }
    if (left == right) {
      res += nums[left];
    }
    return res;
  }
};
