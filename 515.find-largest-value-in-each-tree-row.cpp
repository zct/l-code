/*
 * @lc app=leetcode id=515 lang=cpp
 *
 * [515] Find Largest Value in Each Tree Row
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
//层序遍历
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if(root == nullptr){
            return res;
        }
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        while(!nodeQueue.empty()) {
            int maxVal = 2147483648;
            int size = nodeQueue.size();
            for(int i = 0; i < size; i++){
                TreeNode* frontNode = nodeQueue.front();
                if(frontNode->left != nullptr){
                    nodeQueue.push(frontNode->left);
                }
                if(frontNode->right != nullptr){
                    nodeQueue.push(frontNode->right);
                }
                maxVal = max(maxVal, frontNode->val);
                nodeQueue.pop();
            }
            res.push_back(maxVal);
        }
        return res;
    }
};
// @lc code=end

