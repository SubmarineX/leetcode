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
  // hash table
  bool checkIfExist(vector<int>& arr) {
    unordered_map<int, int> val_index;
    for (int i = 0; i < arr.size(); ++i) {
      if (val_index.find(arr[i] * 2) != val_index.end()) return true;
      if (!(arr[i] & 1) && val_index.find(arr[i] / 2) != val_index.end())
        return true;
      val_index[arr[i]] = i;
    }
    return false;
  }

  // sorting & binary search
  bool checkIfExist(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    for (auto it = arr.begin(); it != arr.end(); ++it) {
      if (*it >= 0) {
        if (binary_search(it + 1, arr.end(), *it * 2)) return true;
      } else {
        if (it != arr.begin()) {
          //                [begin,      end)
          if (binary_search(arr.begin(), it, *it * 2)) return true;  
        }
      }
    }
    return false;
  }
};
