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
 * A square triple (a,b,c) is a triple where a, b, and c are integers and a2 +
 * b2 = c2.
 *
 * Given an integer n, return the number of square triples such that 1 <= a, b,
 * c <= n.
 *
 * Constraints:
 *
 * - 1 <= n <= 250
 */

class Solution {
 public:
  int countTriples(int n) {
    std::vector<int> c2s(n + 1);
    std::unordered_set<int> c2set;
    for (int i = 1; i <= n; ++i) {
      c2s[i] = i * i;
      c2set.emplace(c2s[i]);
    }

    int count = 0;
    for (int a = 1; a < n; ++a) {
      for (int b = a; b < n; ++b) {
        if (c2set.find(c2s[a] + c2s[b]) != c2set.end()) {
          count += 1;
          if (a != b) {
            count += 1;
          }
        }
      }
    }
    return count;
  }
};
