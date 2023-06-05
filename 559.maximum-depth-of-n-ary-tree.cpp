/*
 * @lc app=leetcode id=559 lang=cpp
 *
 * [559] Maximum Depth of N-ary Tree
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
    int maxDepth(Node* root) {
        this->depth = 0;
        dfs(root, 0);
        return this->depth;
    }
    void dfs(Node* root, int len){
        if(root == nullptr){
            return;
        }
        len += 1;
        this->depth=max(this->depth, len);
        for (auto& child : root->children)
            dfs(child, len);
    }
private:
    int depth;
};
// @lc code=end

