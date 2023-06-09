/*
 * @lc app=leetcode id=572 lang=cpp
 *
 * [572] Subtree of Another Tree
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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        this->res = false;
        dfs(root, subRoot);
        return this->res;
    }

    void dfs(TreeNode *root, TreeNode* subRoot){
        if(this->res){
            return;
        }
        if(root == nullptr){
            return;
        }
        if(root->val == subRoot->val){
            if(isSame(root, subRoot)){
                this->res = true;
            }
        }
        dfs(root->left, subRoot);
        dfs(root->right, subRoot);
        
    }

    bool isSame(TreeNode* a, TreeNode* b){
        if(a == nullptr && b == nullptr){
            return true;
        } else { 
            if(a == nullptr){
                return false;
            }
            if (b == nullptr){
                return false;
            }
            if(a->val == b->val){
                return isSame(a->left, b->left) && isSame(a->right, b->right);
            }
        }
        return false;
    }

private:
    bool res;
};
// @lc code=end

