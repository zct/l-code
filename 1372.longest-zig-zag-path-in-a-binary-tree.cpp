/*
 * @lc app=leetcode id=1372 lang=cpp
 *
 * [1372] Longest ZigZag Path in a Binary Tree
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
//dfs的逻辑
class Solution {
public:
    void dfs(TreeNode* root, bool left, int sum){
        ans = max(ans, sum);
        if(root == nullptr){
            return;
        }
        if(left){
            if(root->right){
                dfs(root->right, false, sum+1);
            }
            if(root->left){
                dfs(root->left, true, 1);
            }
        } else {
            if(root->right){
                dfs(root->right, false, 1);
            }
            if(root->left){
                dfs(root->left, true, sum+1);
            }
        }
        return;
    }
    int longestZigZag(TreeNode* root) {
        dfs(root, true, 0);
        dfs(root, false, 0);
        return this->ans;
    }
private:
    int ans;
};
// @lc code=end

