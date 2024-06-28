#include <algorithm>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    vector<int> res;
    int i = 0;
    int j = 0;
    while (i < nums1.size() && j < nums2.size()) {
      if (nums1[i] < nums2[j]) {
        ++i;
        continue;
      }
      if (nums1[i] > nums2[j]) {
        ++j;
        continue;
      }
      if (res.empty() || nums1[i] > res.back()) {
        res.emplace_back(nums1[i]);
      }
      ++i;
      ++j;
    }
    return res;
  }
};
