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
 * Given an integer array nums of length n and an integer target, find three
 * integers in nums such that the sum is closest to target.
 *
 * Return the sum of the three integers.
 *
 * You may assume that each input would have exactly one solution.
 */

class Solution {
 public:
  int threeSumClosest(vector<int>& nums, int target) {
    // cout << "target '" << target << "'" << endl;
    sort(nums.begin(), nums.end());
    assert(nums.size() >= 3);
    int sum = nums[0] + nums[1] + nums[2];
    int diff = abs(target - sum);
    // cout << "sum '" << sum << "' diff '" << diff << "'" << endl;
    for (int i = nums.size() - 1; i >= 2; --i) {
      // cout << "i [" << i << "]='" << nums[i] << "'" << endl;
      int left = 0;
      int right = i - 1;
      while (true) {
        // cout << "left  [" << left << "]='" << nums[left] << "'" << endl;
        // cout << "right [" << right << "]='" << nums[right] << "'" << endl;
        if (left >= right) break;
        int ts = nums[left] + nums[right] + nums[i];
        int td = ts - target ;  // not target - ts
        // cout << "ts '" << ts << "' td '" << td << "'" << endl;
        if (abs(td) < diff) {
          sum = ts;
          diff = abs(td);
          // cout << "sum '" << sum << "' diff '" << diff << "'" << endl;
        }
        if (td == 0) return target;
        if (td < 0) {
          ++left;
        } else {
          --right;
        }
      }
    }
    return sum;
  }
};

int main(int argc, char** argv) {
  vector<int> nums{-1, 2, 1, -4};
  int target = 1;
  Solution solution;
  auto res = solution.threeSumClosest(nums, target);
  cout << "res '" << res << "'" << endl;
  return 0;
}
