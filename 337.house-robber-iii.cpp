/*
 * @lc app=leetcode id=337 lang=cpp
 *
 * [337] House Robber III
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
    int rob(TreeNode* root) {
        int sum = 0;
        return   dfs(root, false, sum);
    }

   int dfs(TreeNode* root, bool parentLink, int sum){
       if(root == nullptr){
           return 0;
       }
       if(parentLink){
           return dfs(root->left, false, sum) + dfs(root->right, false, sum);
       }  
           int trueLeft = dfs(root->left, true, sum);
           int trueRight = dfs(root->right, true, sum);
           int falseLeft = dfs(root->left, false, sum);
           int falseRight = dfs(root->right, false, sum);
           return max(trueLeft+trueRight+root->val, falseLeft+falseRight);
    }

private:
    int res;
};
// @lc code=end

