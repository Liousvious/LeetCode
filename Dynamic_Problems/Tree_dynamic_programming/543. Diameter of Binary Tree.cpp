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
    int maxL = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        dfsSearch(root);
        return maxL;
    }

    int dfsSearch(TreeNode* root) {
        if (!root) return 0;
        int left = dfsSearch(root->left);
        int right = dfsSearch(root->right);
        maxL = max(maxL, left + right);
        return max(left, right) + 1;
    }
};