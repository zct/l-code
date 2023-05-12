/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
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
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr){
            return true;
        }
        return helper(root->left, root->right);
    }
    bool helper(TreeNode* left, TreeNode* right){
        if(left == nullptr || right == nullptr){
            if(left == nullptr && right == nullptr){
                return true;
            } 
            return false;
        }
        if(left->val != right->val){
            return false;
        } else {
            return helper(left->left, right->right) && helper(left->right, right->left);
        }
    }
};
// @lc code=end

