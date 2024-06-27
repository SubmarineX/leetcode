#include <algorithm>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int k = m + n - 1;
    int i = m - 1;
    int j = n - 1;
    while (i >= 0 && j >= 0) {
      if (nums1[i] > nums2[j]) {
        nums1[k] = nums1[i];
        i--;
      } else {
        nums1[k] = nums2[j];
        j--;
      }
      k--;
    }
    while (i >= 0) {
      nums1[k] = nums1[i];
      i--;
      k--;
    }
    while (j >= 0) {
      nums1[k] = nums2[j];
      j--;
      k--;
    }
  }

  // ...

  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int k = m + n - 1;
    int i = m - 1;
    int j = n - 1;
    while (j >= 0) {  // The remaining num1 does not need to be processed
      if (i >= 0 && nums1[i] > nums2[j]) {  // Note i >= 0
        nums1[k--] = nums1[i--];
      } else {
        nums1[k--] = nums2[j--];
      }
    }
  }

  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m;
    int j = 0;
    while (j < n) {
      nums1[i++] = nums2[j++];
    }
    sort(nums1.begin(), nums1.end());
  }
};
