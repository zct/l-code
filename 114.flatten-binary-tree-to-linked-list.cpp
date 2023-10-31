/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
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

class Solution {
public:
    void dfs(TreeNode* root){
        if (root == nullptr){
            return ;
        }else if(pre == nullptr){
            pre = root;
        } else {
            pre->left = nullptr;
            pre->right = root;
            pre = pre->right;
        }
        TreeNode* right = root->right;
        dfs(root->left);
        dfs(right);
    }
    void flatten(TreeNode* root) {
        pre = new(TreeNode);
        dfs(root);
    }
private:
    TreeNode* pre;
};
// @lc code=end

