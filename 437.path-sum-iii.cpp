/*
 * @lc app=leetcode id=437 lang=cpp
 *
 * [437] Path Sum III
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
    int pathSum(TreeNode* root, int targetSum) {
        vector<int> parentNum;
        this->targetSum = targetSum;
        dfs(root, 0, parentNum);
        return this->res;
    }
    void dfs(TreeNode* root, long curSum, vector<int>& parentNum){
        if(root == nullptr){
            return;
        }
        curSum = root->val + curSum;
        if(curSum == targetSum){
            this->res++;
        }
        long tSum = curSum;
        for(auto num : parentNum){
            tSum = tSum - num;
            if(tSum == this->targetSum){
                this->res++;
            }
        }
        parentNum.push_back(root->val);
        if(root->left != nullptr){
            dfs(root->left, curSum, parentNum);
        }
        if(root->right != nullptr){
            dfs(root->right, curSum, parentNum);
        }
        parentNum.pop_back();
    }
private:
    int res;
    int targetSum;
};
// @lc code=end

