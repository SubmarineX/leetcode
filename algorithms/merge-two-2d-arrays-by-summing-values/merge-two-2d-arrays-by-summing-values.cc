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
 * You are given two 2D integer arrays nums1 and nums2.
 *
 * - nums1[i] = [idi, vali] indicate that the number with the id idi has a value
 * equal to vali.
 * - nums2[i] = [idi, vali] indicate that the number with the id idi has a value
 * equal to vali.
 *
 * Each array contains unique ids and is sorted in ascending order by id.
 *
 * Merge the two arrays into one array that is sorted in ascending order by id,
 * respecting the following conditions:
 *
 * - Only ids that appear in at least one of the two arrays should be included
 * in the resulting array.
 * - Each id should be included only once and its value should be the sum of the
 * values of this id in the two arrays. If the id does not exist in one of the
 * two arrays then its value in that array is considered to be 0.
 *
 * Return the resulting array. The returned array must be sorted in ascending
 * order by id.
 */

class Solution {
 public:
  vector<vector<int>> mergeArrays(vector<vector<int>>& nums1,
                                  vector<vector<int>>& nums2) {
    vector<vector<int>> res;
    int i = 0;
    int j = 0;
    while (i < nums1.size() && j < nums2.size()) {
      if (nums1[i].front() < nums2[j].front()) {  // nums[i].front() not nums[i]
        res.emplace_back(nums1[i++]);
      } else if (nums1[i].front() > nums2[j].front()) {
        res.emplace_back(nums2[j++]);
      } else {
        res.emplace_back(nums1[i++]);
        res.back().back() += nums2[j++].back();
      }
    }
    while (i < nums1.size()) {
      res.emplace_back(nums1[i++]);
    }
    while (j < nums2.size()) {
      res.emplace_back(nums2[j++]);
    }
    return res;
  }
};
