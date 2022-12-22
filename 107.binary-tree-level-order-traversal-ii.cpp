/*
 * @lc app=leetcode id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
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
    //解法1：用数组来存储
    //解法2：
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        dfs(root, 0);
        reverse(res.begin(), res.end());
        return res;
    }

   void  dfs(TreeNode* root, int index){
       if(root == nullptr){
           return;
       }
       if(res.size() <= index){
           res.push_back(vector<int>{});
       }
       res[index].push_back(root->val);
       dfs(root->left, index+1);
       dfs(root->right, index+1);
   }
    private:
        vector<vector<int> > res;
};
// @lc code=end

