/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
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

//左根右
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        this->count = 0;
        this->res = 0;
        preOrder(root, k);
        return this->res;
    }
    void preOrder(TreeNode* root, int k){
        if(root == nullptr){
            return;
        }
        preOrder(root->left, k);
       if(++count == k){
        this->res = root->val;
        return;
       }
        preOrder(root->right, k);
    }
    private:
        int count;
        int res;
};
// @lc code=end

