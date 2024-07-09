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
 * You are given an integer array height of length n. There are n vertical lines
 * drawn such that the two endpoints of the ith line are (i, 0) and (i,
 * height[i]).
 *
 * Find two lines that together with the x-axis form a container, such that the
 * container contains the most water.
 *
 * Return the maximum amount of water a container can store.
 *
 * Notice that you may not slant the container.
 */

class Solution {
 public:
  int maxArea(vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;
    int64_t res = -1;
    while (left < right) {
      res = max<int64_t>(
          res, (right - left) * min<int64_t>(height[left], height[right]));
      // The water height depends on the smaller height, so we need to move the
      // index of the smaller height to potentially find a greater height and
      // collect more water.
      height[left] < height[right] ? ++left : --right;
    }
    return res;
  }
};

int main(int argc, char** argv) {
  vector<int> height{1, 10, 20, 1};
  Solution solution;
  auto res = solution.maxArea(height);
  cout << "res '" << res << "'" << endl;
  return 0;
}
