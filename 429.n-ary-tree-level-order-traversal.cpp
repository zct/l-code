/*
 * @lc app=leetcode id=429 lang=cpp
 *
 * [429] N-ary Tree Level Order Traversal
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> nodeQueue;
        vector<vector<int>> res;
        if(root == nullptr){
            return res;
        }
        //nodeQueue not empty
        nodeQueue.push(root);
        while(!nodeQueue.empty()){
            int size  = nodeQueue.size();
            vector<int> vecVal;
            for(int i = 0 ; i < size; i++){
                Node* topNode = nodeQueue.front();
                for(auto child : topNode->children){
                    nodeQueue.push(child);
                }
                vecVal.push_back(topNode->val);
                nodeQueue.pop();
            }
            res.push_back(vecVal);
        }
        return res;
    }
};
// @lc code=end

