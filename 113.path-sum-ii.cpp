/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
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

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return res;
        }
        this->targetSum = targetSum;
       dfs(root, 0, this->sumPath);
       return this->res;
    }

    void dfs(TreeNode* root, int sum, vector<int>& path) {
        if(root == nullptr){
            return;
        }
        this->sumPath.push_back(root->val);
        sum += root->val;
        if(root->left == nullptr && root->right == nullptr) {
            if(sum == this->targetSum) {
                this->res.push_back(vector<int>(path));
            }
        } else {
        dfs(root->left, sum, this->sumPath);
        dfs(root->right, sum, this->sumPath);
        }
        this->sumPath.pop_back();
        return;
    }
private:
    vector<int> sumPath;
    vector<vector<int> > res;
    int targetSum;
};
// @lc code=end

