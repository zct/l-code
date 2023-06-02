/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
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
    bool isBalanced(TreeNode* root) {
        this->res = true;
        depth(root);
        return this->res;
    }

    int depth(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int leftDepth = depth(root->left);
        int rightDepth = depth(root->right);
        if(abs(leftDepth - rightDepth) > 1 ){
            res = false;
        } 
        return max(leftDepth, rightDepth) +1;
    }
private:
    bool res;
};
// @lc code=end

