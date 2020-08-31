#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for a binary tree node.
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int result = 0;
    int maxPathSum(TreeNode* root) {
        if (!root) return 0;
        result = root->val;
        dfs(root);
        return result;
    }

    int dfs(TreeNode* root) {
        if (!root) return 0;
        int left = max(dfs(root->left), 0);
        int right = max(dfs(root->right), 0);
        result = max(result, root->val + left + right);
        return root->val + max(right, left);
    }
};