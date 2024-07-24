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
 * Given a string s consisting of lowercase English letters, return the first
 * letter to appear twice.
 *
 * Note:
 *
 * - A letter a appears twice before another letter b if the second occurrence
 * of a is before the second occurrence of b.
 * - s will contain at least one letter that appears twice.
 *
 * Constraints:
 *
 * - 2 <= s.length <= 100
 * - s consists of lowercase English letters.
 * - s has at least one repeated letter.
 */

class Solution {
 public:
  char repeatedCharacter(string s) {
    if (s.length() < 2) return '\0';
    bool letters[26]{false};
    for (auto &&c : s) {
      const int i = c - 'a';
      if (letters[i]) return c;
      letters[i] = true;
    }
    return '\0';
  }
};
