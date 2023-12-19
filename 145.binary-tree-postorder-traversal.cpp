/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
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
    vector<int> postorderTraversal(TreeNode* root) {
        dfs(root);
        return this->res;
    }
    void dfs(TreeNode* root){
        if(root == nullptr){
            return;
        }
        dfs(root->left);
        dfs(root->right);
        res.push_back(root->val);
    }
private:
    vector<int> res;
};
// @lc code=end

