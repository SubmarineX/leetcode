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
 * Given an integer array nums, rotate the array to the right by k steps, where
 * k is non-negative.
 */

class Solution {
 public:
  void rotate(vector<int>& nums, int k) {
    int i = 0;
    int count = 0;
    // Multiple loops exist if the `count` is less than `nums.size` after one
    // loop. Therefore, we need to start traversing from 0, using each position
    // sequentially as the starting point of a loop.
    // Exist multiple loops with case `nums = [-1,-100,3,99], k = 2`:
    // [0][2],[1][3]
    while (count < nums.size()) {
      int from = i;
      int t1 = nums[from];
      int t2 = 0;
      while (true) {
        // move [from] to [to], then calc next index pair <from, to>
        int to = (from + k) % nums.size();
        t2 = nums[to];  // hold nums[to] temp
        nums[to] = t1;
        from = to;
        ++count;  // Record the count of movements
        if (from == i) break;
        t1 = t2;
      }
      ++i;
    }
  }
};
