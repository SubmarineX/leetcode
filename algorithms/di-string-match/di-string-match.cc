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
  vector<int> diStringMatch(string s) {
    vector<int> res;
    res.reserve(s.size() + 1);
    int l = 0;
    int r = s.size();
    for (auto &&c : s) {
      if (c == 'I') {
        res.emplace_back(l++);
      } else {
        res.emplace_back(r--);
      }
    }
    res.emplace_back(l);
    return res;
  }
};
