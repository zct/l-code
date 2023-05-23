/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
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
//层序遍历,每一层最后一个元素就是最右边的
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(root == nullptr){
            return res;
        }
        queue<TreeNode*>  nodeQueue;
        nodeQueue.push(root);
        while(!nodeQueue.empty()){
            int size = nodeQueue.size();
            for(int i = 0; i < size; i++){
                TreeNode* tmp = nodeQueue.front();
                nodeQueue.pop();
                if(tmp->left != nullptr) nodeQueue.push(tmp->left);
                if(tmp->right != nullptr) nodeQueue.push(tmp->right);
                if(i == size -1){
                    res.push_back(tmp->val);
                }
            }
        }
        return res;
    }
};
// @lc code=end

