/*
 * @lc app=leetcode id=235 lang=cpp
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* res;
        while(root != nullptr){
            if(root->val < min(p->val, q->val)){
                root = root->right;
            } else if(root->val > max(p->val, q->val)){
                root = root->left;
            } else {
                res = root;
                break;
            }
        }
        return res;
    }
    
private:
};
// @lc code=end

