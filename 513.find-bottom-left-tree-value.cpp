/*
 * @lc app=leetcode id=513 lang=cpp
 *
 * [513] Find Bottom Left Tree Value
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
    //层次遍历
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        int res;
        while(!nodeQueue.empty()){
            int n = nodeQueue.size();
            for(int i = 0; i < n; i++){
                TreeNode* t = nodeQueue.front();
                if(i == 0) res = t->val;
                nodeQueue.pop();
                if(t->left) {
                    nodeQueue.push(t->left);
                }
                if(t->right) nodeQueue.push(t->right);
            }
        }
        return res;
    }
};
// @lc code=end

