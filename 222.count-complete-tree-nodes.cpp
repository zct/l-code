/*
 * @lc app=leetcode id=222 lang=cpp
 *
 * [222] Count Complete Tree Nodes
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
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    //递归遍历
    int countNodes(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        int leftH = 0;
        int rightH = 0;
        TreeNode* leftNode = root->left;
        TreeNode* rightNode = root->right;
        while(leftNode != nullptr){
            leftH++;
            leftNode = leftNode->left;
        }
        while(rightNode != nullptr){
            rightH++;
            rightNode = rightNode->right;
        }
        if(leftH == rightH){
            return (2 << leftH) -1;
        } else {
            return countNodes(root->left) + countNodes(root->right) +1;
        }
    }
};
// @lc code=end

