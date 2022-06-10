

#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

#include "../treenode.hpp"

using std::vector;

// Given the root of a binary tree, return the inorder traversal of its nodes'
// values

// Input: root = [1,null,2,3]
// Output: [1,3,2]
// Example 2:

// Input: root = []
// Output: []
// Example 3:

// Input: root = [1]
// Output: [1]

// Constraints:

// The number of nodes in the tree is in the range [0, 100].
// -100 <= Node.val <= 100

// Follow up: Recursive solution is trivial, could you do it iteratively?

class Solution {
public:
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> ans{};
    __inorderTraversal_t(root, ans);
    return ans;
  }

  void __inorderTraversal_t(TreeNode *node, vector<int> &ans) {
    if (node == nullptr) return;
    if (node->left)
      __inorderTraversal_t(node->left, ans);
    ans.emplace_back(node->val);
    if (node->right)
      __inorderTraversal_t(node->right, ans);
  }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Inorder Traversal.
// Memory Usage: 8.4 MB, less than 76.27% of C++ online submissions for Binary Tree Inorder Traversal
