/*
 * @lc app=leetcode id=701 lang=cpp
 *
 * [701] Insert into a Binary Search Tree
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* addNode = new(TreeNode);
        addNode->val = val;
        if(root == nullptr){
            return addNode;
        }
        TreeNode* curr = root;
        TreeNode* prevRoot = nullptr;
        while(curr != nullptr){
            prevRoot = curr;
            if(curr->val > val){
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
        if(prevRoot->val > val){
            prevRoot->left = addNode;
        } else {
            prevRoot->right = addNode;
        }
        return root;
    }
};
// @lc code=end

