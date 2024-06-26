#include <algorithm>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    int i = 0;
    while (i + 3 < nums.size()) {
      int j = i + 1;
      while (j + 2 < nums.size()) {
        int l = j + 1;
        int r = nums.size() - 1;
        const int64_t t = static_cast<int64_t>(target) - nums[i] - nums[j];
        while (l < r) {
          const int64_t v = nums[l] + nums[r];
          if (v == t) {
            res.emplace_back(vector<int>{nums[i], nums[j], nums[l], nums[r]});
            ++l;
            while (l < r && nums[l] == nums[l - 1]) {
              ++l;
            }
            --r;
            while (l < r && nums[r] == nums[r + 1]) {
              --r;
            }
          } else if (v < t) {
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
        ++j;
        while (j + 2 < nums.size() && nums[j] == nums[j - 1]) {
          ++j;
        }
      }
      ++i;
      while (i + 3 < nums.size() && nums[i] == nums[i - 1]) {
        ++i;
      }
    }
    return res;
  }
};
