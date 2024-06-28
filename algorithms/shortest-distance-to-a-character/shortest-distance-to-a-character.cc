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
  vector<int> shortestToChar(string s, char c) {
    vector<int> res(s.size(), -1);
    int l = -10000;
    int r = 10000;
    for (int i = 0; i < s.size(); i++) {
      if (r == 10000) {
        auto k = s.find_first_of(c, i);  // find next`c` in range [i, s.size())
        if (k != s.npos) {
          r = k;
        }
      }
      res[i] = min(i - l, r - i);
      if (!res[i]) {
        l = r;
        r = 10000;
      }
    }
    return res;
  }
};
