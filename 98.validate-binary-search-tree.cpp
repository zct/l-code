/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
    bool isValidBST(TreeNode* root) {
        InOrder(root);
        bool valid = true;
        for(int i = 1; i < this->vecInOrder.size(); i++){
            if(this->vecInOrder[i] <= this->vecInOrder[i-1]) {
                valid = false;
            }
        }
        return valid;
    }

    void InOrder(TreeNode* root){
        if(root == nullptr) {
            return;
        }
        InOrder(root->left);
        this->vecInOrder.push_back(root->val);
        InOrder(root->right);
    }

    private:
    vector<int> vecInOrder;
};
// @lc code=end

