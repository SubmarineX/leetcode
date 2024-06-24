#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  // binary search
  vector<int> twoSum(vector<int>& numbers, int target) {
    for (int i = 0; i < numbers.size(); i++) {
      int o = target - numbers[i];
      auto it = lower_bound(numbers.begin() + i + 1, numbers.end(), o);
      if (it == numbers.end()) continue;
      if (*it > o) continue;
      if (*it == o) return {i + 1, static_cast<int>(it - numbers.begin()) + 1};
    }
    return {-1, -1};
  }

  // ...

  // tow pointers
  vector<int> twoSum(vector<int>& numbers, int target) {
    int l = 0;
    int r = numbers.size() - 1;
    while (l < r) {
      const auto v = numbers[l] + numbers[r];
      if (v == target) return {l + 1, r + 1};
      if (v < target) {
        ++l;
      } else {
        --r;
      }
    }
    return {-1, -1};
  }
};
