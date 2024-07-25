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
 * Given an integer n, return a string array answer (1-indexed) where:
 *
 * - answer[i] == "FizzBuzz" if i is divisible by 3 and 5.
 * - answer[i] == "Fizz" if i is divisible by 3.
 * - answer[i] == "Buzz" if i is divisible by 5.
 * - answer[i] == i (as a string) if none of the above conditions are true.
 *
 * Constraints:
 *
 * - 1 <= n <= 104
 */

class Solution {
 public:
  vector<string> fizzBuzz(int n) {
    vector<string> answer(n);
    for (int i = 15; i <= n; i += 15) {
      answer[i - 1] = "FizzBuzz";
    }
    for (int i = 3; i <= n; i += 3) {
      if (answer[i - 1].empty()) answer[i - 1] = "Fizz";
    }
    for (int i = 5; i <= n; i += 5) {
      if (answer[i - 1].empty()) answer[i - 1] = "Buzz";
    }
    for (int i = 1; i <= n; i += 1) {
      if (answer[i - 1].empty()) answer[i - 1] = std::to_string(i);
    }
    return answer;
  }
};
