#include <algorithm>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

class Solution {
 public:
  int removeElement(vector<int>& nums, int val) {
    int i = 0;
    int j = 0;
    while (j < nums.size()) {
      if (nums[j] != val) {
        nums[i] = nums[j];
        i++;
      }
      j++;
    }
    return i;
  }
};
