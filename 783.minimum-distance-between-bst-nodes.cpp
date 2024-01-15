/*
 * @lc app=leetcode id=783 lang=cpp
 *
 * [783] Minimum Distance Between BST Nodes
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        int prev = -1;
        ans = __INT32_MAX__;
        inOrder(root, prev);
        return this->ans;
    }

    void inOrder(TreeNode *root, int& prev){
        if(root == nullptr){
            return;
        }
        inOrder(root->left, prev);
        if(prev == -1){
            prev = root->val;
        } else {
            ans = min(ans, root->val - prev);
            prev = root->val;
        }
        inOrder(root->right, prev);
    }
private:
    int ans;
};
// @lc code=end

