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
  void duplicateZeros(vector<int>& arr) {
    int zero_count = count(arr.begin(), arr.end(), 0);
    for (int i = arr.size() - 1; i >= 0; --i) {
      const int new_index = i + zero_count;
      if (new_index < arr.size()) {
        arr[new_index] = arr[i];
      }
      if (!arr[i]) {
        --zero_count;
        const int new_index = i + zero_count;
        if (new_index < arr.size()) {
          arr[new_index] = arr[i];
        }
      }
    }
  }
};
