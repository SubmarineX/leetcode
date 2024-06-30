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
 * You are given a 0-indexed, strictly increasing integer array nums and a
 * positive integer diff. A triplet (i, j, k) is an arithmetic triplet if the
 * following conditions are met:
 * - i < j < k,
 * - nums[j] - nums[i] == diff, and
 * - nums[k] - nums[j] == diff.
 * Return the number of unique arithmetic triplets.
 */

class Solution {
 public:
  int arithmeticTriplets(vector<int>& nums, int diff) {
    int count = 0;
    for (int i = nums.size() - 3; i >= 0; --i) {
      if (binary_search(nums.begin() + i + 1, nums.end(), nums[i] + diff) &&
          binary_search(nums.begin() + i + 2, nums.end(),
                        nums[i] + diff + diff))
        count += 1;
    }
    return count;
  }

  // ...

  int arithmeticTriplets(vector<int>& nums, int diff) {
    int count = 0;
    unordered_set<int> set{nums.begin(), nums.end()};
    for (int i = 0; i < nums.size(); ++i) {
      if (set.find(nums[i] + diff) != set.end() &&
          set.find(nums[i] + diff + diff) != set.end())
        count += 1;
    }
    return count;
  }
};

int main(int argc, char** argv) {
  Solution solution;
  vector<int> nums{4, 7, 9, 10};
  int diff = 5;
  auto res = solution.arithmeticTriplets(nums, diff);
  cout << "res '" << res << "'" << endl;
  return 0;
}
