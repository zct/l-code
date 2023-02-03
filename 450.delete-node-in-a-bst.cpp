/*
 * @lc app=leetcode id=450 lang=cpp
 *
 * [450] Delete Node in a BST
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
    TreeNode* adjustBST(TreeNode* root){
        if(root == nullptr){
            return nullptr;
        }
        if(root->left == nullptr  && root->right == nullptr){
            return nullptr;
        } else if(root->right == nullptr){
            swap(root->val, root->left->val);
            root->left = adjustBST(root->left);
        } else {
            swap(root->val, root->right->val);
            root->right = adjustBST(root->right);
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* searchNode = root;
        while(searchNode != nullptr){
            if(searchNode->val == key){
                break;
            } else if(searchNode->val > key){
                searchNode = searchNode->left;
            } else {
                searchNode = searchNode->right;
            }
        }
        searchNode = adjustBST(searchNode);
        return root;
    }
};
// @lc code=end

