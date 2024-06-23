#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  // brute
  vector<int> twoSum(vector<int> &nums, int target) {
    for (int i = nums.size() - 1; i > 0; i--)
      for (int j = i - 1; j >= 0; j--) {
        if (nums[i] + nums[j] == target) {
          return {j, i};
        }
      }
    return {-1, -1};
  }

  // sort
  vector<int> twoSum(vector<int> &nums, int target) {
    vector<pair<int, int16_t>> num_indexes(nums.size());
    for (size_t i = 0; i < nums.size(); i++) {
      num_indexes[i].first = nums[i];
      num_indexes[i].second = i;
    }
    sort(num_indexes.begin(), num_indexes.end());
    size_t hint_j = num_indexes.size() - 1;
    for (size_t i = 0; i < hint_j; i++) {
      for (size_t j = hint_j; j > i; j--) {
        auto s = num_indexes[i].first + num_indexes[j].first;
        if (s > target) continue;
        if (s == target) return {num_indexes[i].second, num_indexes[j].second};
        hint_j = j;
        break;
      }
    }
    return {-1, -1};
  }

  // hash table
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int16_t> num_indexes;
    for (int i = 0; i < nums.size(); i++) {
      auto it = num_indexes.find(target - nums[i]);
      if (it != num_indexes.end()) return {it->second, i};
      // store <x, index of x>
      num_indexes.emplace(nums[i], i);
    }
    return {-1, -1};
  }

  // ...

  // hash table
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int16_t> num_indexes;
    for (int i = 0; i < nums.size(); i++) {
      auto it = num_indexes.find(nums[i]);
      if (it != num_indexes.end()) return {it->second, i};
      // store <y, index of x>
      num_indexes.emplace(target - nums[i], i);
    }
    return {-1, -1};
  }
};
