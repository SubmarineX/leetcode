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
 * You have an array of floating point numbers averages which is initially
 * empty. You are given an array nums of n integers where n is even.
 *
 * You repeat the following procedure n / 2 times:
 *
 * - Remove the smallest element, minElement, and the largest element
 * maxElement, from nums.
 *
 * - Add (minElement + maxElement) / 2 to averages.
 *
 * Return the minimum element in averages.
 */

class Solution {
 public:
  double minimumAverage(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    double res = 51;
    for (int i = 0, j = nums.size() - 1; i < j; ++i, --j) {
      auto t = (static_cast<double>(nums[i]) + nums[j]) / 2;
      if (t < res) res = t;
    }
    return res;
  }
};
