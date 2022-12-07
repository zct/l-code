/*
 * @lc app=leetcode id=99 lang=cpp
 *
 * [99] Recover Binary Search Tree
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
    void recoverTree(TreeNode* root) {
        if(root == nullptr){
            return;
        }
        InOrder(root);
        int first = root->val;
        int second = root->val;
        for(int i = 0; i < vecInOrder.size() -1; i++){
            if(vecInOrder[i] > vecInOrder[i+1]){
                first =  vecInOrder[i];
                break;
            }
        }

        for(int i = vecInOrder.size() -1; i >=1 ; i--){
            if(vecInOrder[i] < vecInOrder[i-1]) {
                second = vecInOrder[i];
                break;
            }
        }
        int temp = mapNode[second]->val;
        mapNode[second]->val = mapNode[first]->val;
        mapNode[first]->val = temp;
        
    }

    void InOrder(TreeNode * root){
        if(root == nullptr){
            return;
        }

        InOrder(root->left);
        this->vecInOrder.push_back(root->val);
        this->mapNode[root->val] = root;
        InOrder(root->right);
    }

    private:
    vector<int> vecInOrder;
    map<int, TreeNode*> mapNode;
};
// @lc code=end

