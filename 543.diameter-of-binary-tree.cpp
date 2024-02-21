/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
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
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return this->res;
    }
    int dfs(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int left = dfs(root->left) ;
        int right = dfs(root->right) ;
        res = max(left+right, res);
        return max(left, right) + 1;
    }
private:
    int res;
};
// @lc code=end

