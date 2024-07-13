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
 * Given an array nums with n objects colored red, white, or blue, sort them
 * in-place so that objects of the same color are adjacent, with the colors in
 * the order red, white, and blue.
 *
 * We will use the integers 0, 1, and 2 to represent the color red, white, and
 * blue, respectively.
 *
 * You must solve this problem without using the library's sort function.
 */

class Solution {
 public:
  void sortColors(vector<int>& nums) {
    int red = 0;
    int white = 0;
    int blue = 0;
    for (int i = 0; i < nums.size(); ++i) {
      switch (nums[i]) {
        case 0:
          red += 1;
          break;

        case 1:
          white += 1;
          break;

        case 2:
          blue += 1;
          break;

        default:
          assert(false);
          break;
      }
    }

    int i = 0;
    int right = red;
    while (i < right) {
      nums[i++] = 0;
    }
    right += white;
    while (i < right) {
      nums[i++] = 1;
    }
    right += blue;
    while (i < right) {
      nums[i++] = 2;
    }
  }
};
