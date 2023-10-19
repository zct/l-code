/*
 * @lc app=leetcode id=652 lang=cpp
 *
 * [652] Find Duplicate Subtrees
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
    string dfs(TreeNode * root){
        string res;
        if(root == nullptr){
            return "";
        }
        res.append(to_string(root->val));
        res.append(",");
        res.append(dfs(root->left));
        res.append(",");
        res.append(dfs(root->right));
        treeMap[res]++;
        if(treeMap[res] == 2){
            vecTree.push_back(root);
        }
        return res;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return vecTree;
    }
private:
    map<string, int> treeMap;
    vector<TreeNode*> vecTree;
};
// @lc code=end

