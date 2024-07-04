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
 * You are given a 0-indexed integer array nums having length n, an integer
 * indexDifference, and an integer valueDifference.
 *
 * Your task is to find two indices i and j, both in the range [0, n - 1], that
 * satisfy the following conditions:
 *
 * - abs(i - j) >= indexDifference, and
 * - abs(nums[i] - nums[j]) >= valueDifference
 *
 * Return an integer array answer, where answer = [i, j] if there are two such
 * indices, and answer = [-1, -1] otherwise. If there are multiple choices for
 * the two indices, return any of them.
 *
 * Note: i and j may be equal.
 */

class Solution {
 public:
  vector<int> findIndices(vector<int>& nums, int indexDifference,
                          int valueDifference) {
    for (int i{0}; i + indexDifference < nums.size(); ++i) {
      for (int j{i + indexDifference}; j < nums.size(); ++j) {
        if (abs(nums[i] - nums[j]) >= valueDifference)
          return vector<int>{i, j};  // not vector<int>(i, j)
      }
    }
    return vector<int>{-1, -1};
  }
};

int main(int argc, char** argv) {
  vector<int> nums{5, 1, 4, 1};
  int indexDifference = 2;
  int valueDifference = 4;
  Solution solution;
  auto res = solution.findIndices(nums, indexDifference, valueDifference);
  cout << "res '" << res.front() << "' '" << res.back() << "'" << endl;
  return 0;
}
