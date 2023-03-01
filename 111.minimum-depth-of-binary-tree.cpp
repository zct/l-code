/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
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
    int minDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        this->minD = __INT_MAX__;
        dfs(root, 1);
        return this->minD;
    }
    void dfs(TreeNode* root, int depth){
        if(root == nullptr){
            return;
        }
        if(root->left == nullptr && root->right == nullptr){
            this->minD = min(this->minD, depth);
            return;
        }
        dfs(root->left, depth+1);
        dfs(root->right, depth+1);
    }
private:
    int minD;
};
// @lc code=end

