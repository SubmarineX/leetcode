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
 * You are given two positive integers low and high.
 *
 * An integer x consisting of 2 * n digits is symmetric if the sum of the first
 * n digits of x is equal to the sum of the last n digits of x. Numbers with an
 * odd number of digits are never symmetric.
 *
 * Return the number of symmetric integers in the range [low, high].
 *
 * Constraints:
 *
 * - 1 <= low <= high <= 104
 */

class Solution {
 public:
  int countSymmetricIntegers(int low, int high) {
    int count = 0;
    for (int i = low; i <= high; ++i) {
      const auto str = std::to_string(i);
      if (str.length() & 1) continue;
      int sum = 0;
      std::for_each(str.begin(), str.begin() + str.length() / 2,
                    [&sum](auto &c) { sum += c - '0'; });
      std::for_each(str.begin() + str.length() / 2, str.end(),
                    [&sum](auto &c) { sum -= c - '0'; });
      if (!sum) count += 1;
    }
    return count;
  }

  int countSymmetricIntegers(int low, int high) {
    // TODO: By finding the intersection of [low, height] with [10, 99] and
    // [1000, 9999], the number of iterations can be reduced.
  }
};
