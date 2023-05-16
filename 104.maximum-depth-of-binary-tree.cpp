/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
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
    int maxDepth(TreeNode* root) {
        this->maxD = 0;
        dfs(root, 0);
        return this->maxD;
    }
    void dfs(TreeNode* root, int depth){
        if(root == nullptr){
            maxD = max(depth,this->maxD);
            return;
        }
        depth++;
        dfs(root->left, depth);
        dfs(root->right, depth);
    }
    private:
        int maxD;
};
// @lc code=end

