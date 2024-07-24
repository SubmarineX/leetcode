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
 * Given an integer x, return true if x is a palindrome, and false otherwise.
 *
 * Constraints:
 *
 * - -231 <= x <= 231 - 1
 *
 * Follow up: Could you solve it without converting the integer to a string?
 */

class Solution {
 public:
  bool isPalindrome(int x) {
    if (x < 0) return false;
    const std::int64_t a = x;
    std::int64_t b = 0;
    while (x) {
      b = b * 10 + x % 10;
      x /= 10;
    }
    return a == b;
  }

  /**
   * Don't worry about overflow
   */
  bool isPalindrome(int x) {
    if (x < 0 || (x && !(x % 10))) return false;  // x = 10
    const int a = x;
    int b = 0;
    while (x > b) {
      b = b * 10 + x % 10;
      x /= 10;
    }
    return b == x || b / 10 == x;
  }
};
