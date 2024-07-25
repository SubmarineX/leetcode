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
 * Given an integer n (in base 10) and a base k, return the sum of the digits of
 * n after converting n from base 10 to base k.
 *
 * After converting, each digit should be interpreted as a base 10 number, and
 * the sum should be returned in base 10.
 *
 * Constraints:
 *
 * - 1 <= n <= 100
 * - 2 <= k <= 10
 */

class Solution {
 public:
  int sumBase(int n, int k) {
    int sum = 0;
    while (n) {
      sum += n % k;
      n /= k;
    }
    return sum;
  }
};
