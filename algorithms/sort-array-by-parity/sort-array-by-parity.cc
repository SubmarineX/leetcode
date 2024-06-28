#include <algorithm>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> sortArrayByParity(vector<int>& nums) {
    int l = 0;
    int r = nums.size() - 1;
    while (l < r) {
      if (!(nums[l] & 1)) {
        ++l;
        continue;
      }
      if (nums[r] & 1) {
        --r;
        continue;
      }
      swap(nums[l++], nums[r--]);
    }
    return nums;
  }

  // ...

  vector<int> sortArrayByParity(vector<int>& nums) {
    int l = 0;
    int r = nums.size() - 1;
    while (l < r) {
      while (l < r && !(nums[l] & 1)) ++l;
      while (l < r && (nums[r] & 1)) --r;
      if (l < r) swap(nums[l++], nums[r--]);
    }
    return nums;
  }
};
