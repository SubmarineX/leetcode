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
  vector<int> sortArrayByParityII(vector<int>& nums) {
    for (int i = 0, j = 1; i < nums.size() && j < nums.size(); i += 2) {
      if (nums[i] & 1) {
        while (j < nums.size() && (nums[j] & 1)) j += 2;
        swap(nums[i], nums[j]);
      }
    }
    return nums;
  }
};
