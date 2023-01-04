/*
 * @lc app=leetcode id=129 lang=cpp
 *
 * [129] Sum Root to Leaf Numbers
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
    int sumNumbers(TreeNode* root) {
        this->sum = 0;
        dfs(root);
        return this->sum;
    }
    void dfs(TreeNode* root){
        if(root == nullptr){
            return;
        }
        this->stNum.push(root->val);
        dfs(root->left);
        dfs(root->right);
        //leaf node
        if(root->left == nullptr && root->right == nullptr){
            stack<int> stTemp;
            int num = 0;
            int index = 0;
            while(!this->stNum.empty()){
                num = pow(10,index) * stNum.top() + num;
                stTemp.push(stNum.top());
                stNum.pop();
                index++;
            }
            sum += num;
            while(!stTemp.empty()){
                stNum.push(stTemp.top());
                stTemp.pop();
            }
        }
        this->stNum.pop();
    }
private:
    stack<int> stNum;
    int sum = 0;
};
// @lc code=end

