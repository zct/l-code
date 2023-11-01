/*
 * @lc app=leetcode id=687 lang=cpp
 *
 * [687] Longest Univalue Path
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
    int checkVal(TreeNode* root) {
        if (root == nullptr){
            return 0;
        }
        int left = checkVal(root->left);
        int right = checkVal(root->right);
        if(root->left != nullptr && root->val == root->left->val){
            left = left+1;
        } else {
            left = 0;
        }
        if(root->right != nullptr && root->val == root->right->val){
            right = right +1;
        } else {
            right = 0;
        }
        ans = max(ans ,left+right);
        return max(left, right);
    }
    int longestUnivaluePath(TreeNode* root) {
        checkVal(root);
        return this->ans;
    }
private: 
    int ans;
};
// @lc code=end

