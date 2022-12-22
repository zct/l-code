/*
 * @lc app=leetcode id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
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
class Solution {
public:
    //解法1，可以用DFS找出两个节点的路径,然后一比较
    //解法2，递归算法
    //尝试用解法2
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        find(root, p, q);
        return res;
    }

    bool find(TreeNode* root,  TreeNode* p, TreeNode* q){
        if(root == nullptr){
            return false;
        }
        bool rootFind = false;
        if(root == p || root == q){
            rootFind = true;
        }
        bool leftFind = find(root->left, p, q);
        bool  rightFind = find(root->right, p, q);
        if(rootFind && (leftFind || rightFind)){
            res = root;
            return false;
        } else if (leftFind && rightFind){
            res = root;
            return false;
        }
        return leftFind || rightFind || rootFind;
    }
private:
    TreeNode *res;
};
// @lc code=end

