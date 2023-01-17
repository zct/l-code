/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        this->preorder = preorder;
        this->inorder = inorder;
        if(preorder.size() == 0){
            return nullptr;
        }
        return innerBuild(0, preorder.size()-1, 0, inorder.size()-1);
        
    }
    TreeNode* innerBuild(int preBegin, int preEnd, int inBegin, int inEnd){
        if(preBegin > preEnd){
            return nullptr;
        }
        TreeNode* root = new(TreeNode);
        root->val = preorder[preBegin];
        if(preBegin == preEnd){
            return root;
        }
        int sep = 0;
        for(int i = inBegin; i <= inEnd; i++){
            if(inorder[i] == root->val){
                sep = i;
                break;
            }
        }
        root->left = innerBuild(preBegin+1, preBegin+sep-inBegin, inBegin, sep-1);
        root->right = innerBuild(preEnd-(inEnd-sep)+1, preEnd, sep+1 , inEnd);
        return root;
    }
private:
    vector<int> preorder;
    vector<int> inorder;
};
// @lc code=end

