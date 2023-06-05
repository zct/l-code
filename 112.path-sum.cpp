/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        this->res = false;
        this->targetSum = targetSum;
        dfs(root, 0);
        return this->res;
    }
    void dfs(TreeNode* root, int currsum){
        if(root == nullptr){
            return;
        }
        currsum += root->val;
        if(root->left == nullptr && root->right == nullptr){
        if(currsum == this->targetSum){
                this->res = true;
        }
        } else {
            dfs(root->left, currsum);
            dfs(root->right, currsum);
        }
    }
private:
    bool res;
    int targetSum;
};
// @lc code=end

