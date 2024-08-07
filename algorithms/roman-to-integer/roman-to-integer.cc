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
 * Roman numerals are represented by seven different symbols: I, V, X, L, C, D
 * and M.
 *
 * Symbol       Value
 * I             1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000
 * For example, 2 is written as II in Roman numeral, just two ones added
 * together. 12 is written as XII, which is simply X + II. The number 27 is
 * written as XXVII, which is XX + V + II.
 *
 * Roman numerals are usually written largest to smallest from left to right.
 * However, the numeral for four is not IIII. Instead, the number four is
 * written as IV. Because the one is before the five we subtract it making four.
 * The same principle applies to the number nine, which is written as IX. There
 * are six instances where subtraction is used:
 *
 * - I can be placed before V (5) and X (10) to make 4 and 9.
 * - X can be placed before L (50) and C (100) to make 40 and 90.
 * - C can be placed before D (500) and M (1000) to make 400 and 900.
 *
 * Given a roman numeral, convert it to an integer.
 *
 * Constraints:
 *
 * - 1 <= s.length <= 15
 * - s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
 * - It is guaranteed that s is a valid roman numeral in the range [1, 3999].
 */

class Solution {
 public:
  int romanToInt(string s) {
    static const std::unordered_map<std::string, int> m{
        {"I", 1},   {"IV", 4},   {"V", 5},    {"IX", 9},  {"X", 10},
        {"XL", 40}, {"L", 50},   {"XC", 90},  {"C", 100}, {"CD", 400},
        {"D", 500}, {"CM", 900}, {"M", 1000},
    };

    int num = 0;
    for (int i = s.length() - 1; i >= 0; --i) {
      bool more = false;
      switch (s[i]) {
        case 'I':
          break;
        case 'V':
        case 'X':
        case 'L':
        case 'C':
        case 'D':
        case 'M':
          // std::string(size_type count, CharT ch)
          if (i > 0 &&
              m.at(std::string(1, s[i - 1])) < m.at(std::string(1, s[i]))) {
            more = true;
          }
          break;
        default:
          assert(false);
      }
      num +=
          m.at(std::string(s.begin() + (more ? i - 1 : i), s.begin() + i + 1));
      if (more) --i;
    }

    return num;
  }
};

int main(int argc, char** argv) {
  Solution solution;
  auto res = solution.romanToInt("MCMXCIV");
  cout << "res '" << res << "'" << endl;
  return 0;
}
