#include <algorithm>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

class Solution {
 public:
  // two pointers, so slow
  vector<vector<int>> threeSum(vector<int>& nums) {
    std::sort(nums.begin(), nums.end());

    set<vector<int>> res;
    for (int i = 0; i + 2 < nums.size(); i++) {
      int l = i + 1;
      int r = nums.size() - 1;
      const int target = 0 - nums[i];
      while (l < r) {
        const auto v = nums[l] + nums[r];
        if (v == target) {
          res.emplace(vector<int>{nums[i], nums[l], nums[r]});
          ++l;
          --r;
          continue;
        }
        if (v < target) {
          ++l;
        } else {
          --r;
        }
      }
    }

    return vector<vector<int>>(res.begin(), res.end());
  }

  // two pointers, 🚀
  vector<vector<int>> threeSum(vector<int>& nums) {
    std::sort(nums.begin(), nums.end());

    vector<vector<int>> res;
    int i = 0;
    while (i + 2 < nums.size()) {
      int l = i + 1;
      int r = nums.size() - 1;
      const int target = -nums[i];
      while (l < r) {
        const auto v = nums[l] + nums[r];
        if (v == target) {
          res.emplace_back(vector<int>{nums[i], nums[l], nums[r]});
          ++l;
          while (l < r && nums[l] == nums[l - 1]) {
            ++l;
          }
          --r;
          while (l < r && nums[r] == nums[r + 1]) {
            --r;
          }
        } else if (v < target) {
          ++l;
          while (l < r && nums[l] == nums[l - 1]) {
            ++l;
          }
        } else {
          --r;
          while (l < r && nums[r] == nums[r + 1]) {
            --r;
          }
        }
      }
      ++i;
      while (i + 2 < nums.size() && nums[i] == nums[i - 1]) {
        ++i;
      }
    }

    return res;
  }

  // hash table, so slow
  vector<vector<int>> threeSum(vector<int>& nums) {
    set<vector<int>> res;
    unordered_set<int> k_set;

    for (int k = 0; k < nums.size(); k++) {
      if (k_set.find(nums[k]) != k_set.end()) continue;
      k_set.emplace(nums[k]);
      const int target = -nums[k];
      unordered_map<int, int16_t> num_indexes;
      for (int i = k + 1; i < nums.size(); i++) {
        if (i == k) continue;
        auto it = num_indexes.find(target - nums[i]);
        if (it != num_indexes.end()) {
          vector<int> v{nums[k], nums[i], target - nums[i]};
          sort(v.begin(), v.end());
          res.emplace(move(v));
        }
        // store <x, index of x>
        num_indexes.emplace(nums[i], i);
      }
    }

    return vector<vector<int>>(res.begin(), res.end());
  }
};
