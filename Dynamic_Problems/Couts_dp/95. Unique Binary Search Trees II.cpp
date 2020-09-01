#include <bits/stdc++.h>

using namespace std;


 // Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };


class Solution {
public:
    //unordered_map<int, int> memo;
    
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return vector<TreeNode*>{};
        return construct(1, n);    
    }

    vector<TreeNode*> construct(int begin, int end) {
        vector<TreeNode*> res;
        if (begin >end) {
            res.push_back(nullptr);
            return res;
        }

        //if (memo.count(end - begin) > 0) return res;

        for (int i = begin; i <= end; i++) {
            vector<TreeNode*> left_nodes = construct(begin, i - 1);
            vector<TreeNode*> right_nodes = construct(i + 1, end);
            for (TreeNode* left_node : left_nodes) {
                for (TreeNode* right_node : right_nodes) {
                    TreeNode* t = new TreeNode(i);
                    t->left = left_node;
                    t->right = right_node;
                    res.push_back(t);
                    //memo[end - begin] == 1;
                }
            }
        }
        return res;
    }
};


// class Solution {
// public:
//     vector<TreeNode *> generateTrees(int n) {
//         if (n) return generate(1, n);
//         else return vector<TreeNode *>{};
//     }
    
//     vector<TreeNode *> generate(int left, int right) {
//         vector<TreeNode *> ans;
//         if (left > right) {
//             ans.push_back(nullptr);
//             return ans;
//         }
//         for (int i = left; i <= right; i++) {
//             vector<TreeNode *> left_nodes = generate(left, i - 1);
//             vector<TreeNode *> right_nodes = generate(i + 1, right);
//             for (TreeNode *left_node : left_nodes) {
//                 for (TreeNode *right_node : right_nodes) {
//                     TreeNode *t = new TreeNode(i);
//                     t->left = left_node;
//                     t->right = right_node;
//                     ans.push_back(t);
//                 }
//             }
//         }
//         return ans;
//     }
// };