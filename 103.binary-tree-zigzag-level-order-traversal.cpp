/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        dfs(root, 1);
        return this->res;
    }
    void dfs(TreeNode* root, int index){
        if(!root){
            return;
        }
        if(index > res.size()){
            res.push_back(vector<int>{root->val});
        } else {
            if(index % 2 == 0){
                res[index-1].insert(res[index-1].begin(), root->val);
            } else {
                res[index-1].push_back(root->val);
            }
        }
        if(root->left){
            dfs(root->left, index+1);
        } 
        if(root->right){
            dfs(root->right, index+1);
        }
    }
private:
    vector<vector<int>> res;
};
// @lc code=end

