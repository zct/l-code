/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        dfs(root, 1);
        return this->res;
    }

    void dfs(TreeNode* root, int level){
        if(root == nullptr){
            return;
        }
        if(level > res.size()){
            res.push_back(vector<int>{root->val});
        } else {
            res[level-1].push_back(root->val);
        }
        if(root->left){
            dfs(root->left, level+1);
        }
        if(root->right){
            dfs(root->right, level+1);
        }
    }
private:
    vector<vector<int>> res;
};
// @lc code=end

