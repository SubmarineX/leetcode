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
 * Given the root of a binary search tree and an integer k, return true if there
 * exist two elements in the BST such that their sum is equal to k, or false
 * otherwise.
 *
 * Constraints:
 *
 * - The number of nodes in the tree is in the range [1, 104].
 * - -104 <= Node.val <= 104
 * - root is guaranteed to be a valid binary search tree.
 * - -105 <= k <= 105
 */

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  TreeNode *findV(TreeNode *node, int v) {
    while (node) {
      if (node->val == v) return node;
      if (node->val < v) {
        node = node->right;
      } else {
        node = node->left;
      }
    }
    return nullptr;
  }

  bool findTarget(TreeNode *root, int k) {
    if (!root) return false;
    std::queue<TreeNode *> first;
    first.push(root);
    while (!first.empty()) {
      auto node = first.front();
      if (node->left) first.push(node->left);
      if (node->right) first.push(node->right);
      first.pop();
      auto other_node = findV(root, k - node->val);
      if (other_node && other_node != node) return true;  // root = [1], k = 2
    }
    return false;
  }
};
