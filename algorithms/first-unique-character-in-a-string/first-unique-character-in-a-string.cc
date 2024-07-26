#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

/*
 * Given a string s, find the first non-repeating character in it and return its
 * index. If it does not exist, return -1.
 *
 * Constraints:
 *
 * - 1 <= s.length <= 10^5
 * - s consists of only lowercase English letters.
 */

class Solution {
 public:
  int firstUniqChar(string s) {
    // <c, index>
    std::unordered_map<int, int> um;
    for (int i = 0; i < s.length(); ++i) {
      auto it = um.find(s[i]);
      if (it == um.end()) {
        um.emplace(s[i], i);
      } else {
        it->second = -1;
      }
    }

    int min = -1;
    for (const auto& item : um) {
      if (item.second == -1) continue;
      if (min == -1 || min > item.second) {
        min = item.second;
      }
    }
    return min;
  }
};
