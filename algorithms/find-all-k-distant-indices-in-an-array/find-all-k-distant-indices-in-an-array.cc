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
 * You are given a 0-indexed integer array nums and two integers key and k. A
 * k-distant index is an index i of nums for which there exists at least one
 * index j such that |i - j| <= k and nums[j] == key.
 *
 * Return a list of all k-distant indices sorted in increasing order.
 */

class Solution {
 public:
  vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
    int next = 0;
    vector<int> res;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] != key) continue;
      const int l = max(i - k, next);
      const int r = min(i + k, static_cast<int>(nums.size()) - 1);
      for (int j = l; j <= r; ++j) {
        res.emplace_back(j);
      }
      next = r + 1;  // [2,2,2,2,2], 2, 2
    }
    return res;
  }
};
