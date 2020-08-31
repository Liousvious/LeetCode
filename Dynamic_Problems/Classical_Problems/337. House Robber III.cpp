#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for a binary tree node.
 * 
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    unordered_map<TreeNode*, int> memo;
    int rob(TreeNode* root) {
        if (!root) return 0;

        if (memo.count(root) > 0) return memo[root];

        int res = max(root->val + (root->left ? (rob(root->left->left) + rob(root->left->right)) : 0) + \
                (root->right ? (rob(root->right->left) + rob(root->right->right)) : 0), \
                rob(root->left) + rob(root->right));
        memo[root] = res;
        return res;
    }
};