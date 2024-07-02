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
 * You are given a 0-indexed integer array forts of length n representing the
 * positions of several forts. forts[i] can be -1, 0, or 1 where:
 *
 * - -1 represents there is no fort at the ith position.
 * - 0 indicates there is an enemy fort at the ith position.
 * - 1 indicates the fort at the ith the position is under your command.
 *
 * Now you have decided to move your army from one of your forts at position i
 * to an empty position j such that:
 *
 * - 0 <= i, j <= n - 1
 * - The army travels over enemy forts only. Formally, for all k where min(i,j)
 * < k < max(i,j), forts[k] == 0.
 *
 * While moving the army, all the enemy forts that come in the way are captured.
 *
 * Return the maximum number of enemy forts that can be captured. In case it is
 * impossible to move your army, or you do not have any fort under your command,
 * return 0.
 */

class Solution {
 public:
  int captureForts(vector<int>& forts) {
    int min = 0;
    while (min < forts.size() && !forts[min]) {
      ++min;
    }
    int max = forts.size() - 1;
    while (max >= 0 && !forts[max]) {
      --max;
    }
    if (max < min) return 0;
    int left = INT32_MAX;
    int right = INT32_MIN;
    int i = min + 1;
    while (i < max) {
      if (!forts[i]) {
        int t = i;
        while (i < max && !forts[i]) {
          ++i;
        }
        // [1, 0, ..., -1] or [-1, 0, ..., 1]
        if ((forts[t - 1] + forts[i] == 0) &&
            (left > right || i - t > right - left)) {
          left = t;
          right = i;
        }
      } else {
        ++i;
      }
    }
    if (left > right) return 0;
    return right - left;
  }
};
