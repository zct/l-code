/*
 * @lc app=leetcode id=872 lang=cpp
 *
 * [872] Leaf-Similar Trees
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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> aVec;
        vector<int> bVec;
        dfs(root1, aVec);
        dfs(root2, bVec);
        return aVec == bVec;
        
    }
    void dfs(TreeNode * root, vector<int>& res){
        if(root == nullptr){
            return;
        }
        if(root->left == nullptr && root->right == nullptr){
            res.push_back(root->val);
        } else {
            dfs(root->left, res);
            dfs(root->right, res);
        }
    }
};
// @lc code=end

