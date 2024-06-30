#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

class Solution {
 public:
  int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
    int count = 0;
    for (int i = 0; i < arr1.size(); ++i) {
      bool is_found = false;
      for (int j = 0; j < arr2.size(); ++j) {
        if (abs(arr1[i] - arr2[j]) <= d) {
          is_found = true;
          break;
        }
      }
      if (!is_found) count += 1;
    }
    return count;
  }

  int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
    sort(arr2.begin(), arr2.end());
    int count = 0;
    for (auto&& v : arr1) {
      auto it = arr2.end();
      // v <= *it for lower_bound
      // v < *it for upper_bound
      it = upper_bound(arr2.begin(), arr2.end(), v);
      if (it != arr2.end()) {
        if (*it - v <= d) continue;
        if (it != arr2.begin() && v - *(it - 1) <= d) continue;
      } else {
        if (v - arr2.back() <= d) continue;
      }
      count += 1;
    }
    return count;
  }
};

int main(int argc, char** argv) {
  vector<int> arr1{4, 5, 8};
  vector<int> arr2{10, 9, 1, 8};
  int d = 2;
  Solution s;
  int res = s.findTheDistanceValue(arr1, arr2, d);
  cout << "res '" << res << "'" << endl;
  return 0;
}
