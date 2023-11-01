/*
 * @lc app=leetcode id=814 lang=cpp
 *
 * [814] Binary Tree Pruning
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
//use dfs
class Solution {
public:
    bool dfs(TreeNode* root){
        if(root == nullptr){
            return false;
        }
        bool left = dfs(root->left);
        bool right = dfs(root->right);
        if(!left){
            root->left = nullptr;
        }
        if(!right){
            root->right = nullptr;
        }
        if(root->val == 0){
            if(!left && !right){
                return false;
            }
        }
        return true;
    }
    TreeNode* pruneTree(TreeNode* root) {
        bool res = dfs(root);
        if (!res){
            return nullptr;
        }
        return root;
    }
};
// @lc code=end

