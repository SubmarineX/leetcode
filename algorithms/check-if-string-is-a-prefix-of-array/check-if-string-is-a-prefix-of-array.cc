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
  bool isPrefixString(string s, vector<string>& words) {
    int i = 0;
    for (auto&& word : words) {
      if (i >= s.size()) return true;
      if (s.compare(i, word.size(), word)) return false;
      i += word.size();
    }
    return i >= s.size();  // "z", "z"
  }
};

int main(int argc, char** argv) {
  std::string s{"z"};
  vector<string> words{"z"};
  Solution solution;
  auto res = solution.isPrefixString(s, words);
  cout << "res '" << res << "'" << endl;
  return 0;
}
