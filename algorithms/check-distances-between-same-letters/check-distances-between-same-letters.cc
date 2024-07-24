#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

/*
 * You are given a 0-indexed string s consisting of only lowercase English
 * letters, where each letter in s appears exactly twice. You are also given a
 * 0-indexed integer array distance of length 26.
 *
 * Each letter in the alphabet is numbered from 0 to 25 (i.e. 'a' -> 0, 'b' ->
 * 1, 'c' -> 2, ... , 'z' -> 25).
 *
 * In a well-spaced string, the number of letters between the two occurrences of
 * the ith letter is distance[i]. If the ith letter does not appear in s, then
 * distance[i] can be ignored.
 *
 * Return true if s is a well-spaced string, otherwise return false.
 *
 * Constraints:
 *
 * - 2 <= s.length <= 52
 * - s consists only of lowercase English letters.
 * - Each letter appears in s exactly twice.
 * - distance.length == 26
 * - 0 <= distance[i] <= 50
 */

class Solution {
 public:
  bool checkDistances(string s, vector<int>& distance) {
    for (int i = 0; i < s.length(); ++i) {
      int d = distance[s[i] - 'a'];
      if (!((i + d + 1 < s.length() && s[i + d + 1] == s[i]) ||
            (i - d - 1 >= 0 && s[i - d - 1] == s[i]))) {
        return false;
      }
    }
    return true;
  }
};
