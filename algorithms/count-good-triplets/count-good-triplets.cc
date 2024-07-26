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
 * Given an array of integers arr, and three integers a, b and c. You need to
 * find the number of good triplets.
 *
 * A triplet (arr[i], arr[j], arr[k]) is good if the following conditions are
 * true:
 *
 * - 0 <= i < j < k < arr.length
 * - |arr[i] - arr[j]| <= a
 * - |arr[j] - arr[k]| <= b
 * - |arr[i] - arr[k]| <= c
 *
 * Where |x| denotes the absolute value of x.
 *
 * Return the number of good triplets.
 *
 * Constraints:
 *
 * - 3 <= arr.length <= 100
 * - 0 <= arr[i] <= 1000
 * - 0 <= a, b, c <= 1000
 */

class Solution {
 public:
  int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
    int count = 0;
    for (int i = 0; i + 2 < arr.size(); ++i) {
      for (int j = i + 1; j + 1 < arr.size(); ++j) {
        if (std::abs(arr[i] - arr[j]) > a) continue;
        for (int k = j + 1; k < arr.size(); ++k) {
          if (std::abs(arr[j] - arr[k]) <= b &&
              std::abs(arr[i] - arr[k]) <= c) {
            count += 1;
          }
        }
      }
    }
    return count;
  }
};
