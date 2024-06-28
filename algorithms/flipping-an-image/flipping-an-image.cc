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
  vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
    for (auto&& row : image) {
      int i = 0;
      int j = row.size() - 1;
      while (i < j) {
        swap(row[i++], row[j--]);
      }
      for (auto&& v : row) {
        v = v ? 0 : 1;
      }
    }
    return image;
  }

  // ...

  vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
    for (auto&& row : image) {
      int i = 0;
      int j = row.size() - 1;
      while (i < j) {
        int t = row[i] ^ 1;
        row[i] = row[j] ^ 1;
        row[j] = t;
        ++i;
        --j;
      }
      if (i == j) {
        row[i] ^= 1;
      }
    }
    return image;
  }

  vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
    for (auto&& row : image) {
      reverse(row.begin(), row.end());
      for (auto&& v : row) {
        v = v ? 0 : 1;
      }
    }
    return image;
  }
};
