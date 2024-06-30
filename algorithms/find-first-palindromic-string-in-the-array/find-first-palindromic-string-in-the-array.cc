#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

class Solution {
 public:
  string firstPalindrome(vector<string>& words) {
    for (auto&& word : words) {
      int l = 0;
      int r = word.size() - 1;
      bool is_palindromic = true;
      while (l < r) {
        if (word[l++] != word[r--]) {
          is_palindromic = false;
          break;
        }
      }
      if (is_palindromic) return word;
    }
    return "";
  }
};
