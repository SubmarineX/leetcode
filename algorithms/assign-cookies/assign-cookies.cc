#include <algorithm>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

class Solution {
 public:
  int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int count = 0;
    int i = g.size() - 1;
    int j = s.size() - 1;
    while (i >= 0 && j >= 0) {
      if (g[i] > s[j]) {
        --i;
        continue;
      }
      --i;
      --j;
      ++count;
    }
    return count;
  }
};
