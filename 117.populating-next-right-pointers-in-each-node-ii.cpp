/*
 * @lc app=leetcode id=117 lang=cpp
 *
 * [117] Populating Next Right Pointers in Each Node II
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr)
        {
            return nullptr;
        }
        queue<Node *> nodeQueue;
        nodeQueue.push(root);
        while (nodeQueue.size() != 0)
        {
            int size = nodeQueue.size();
            for (int i = 0; i < size; i++)
            {
                Node *prev = nodeQueue.front();
                if (prev->left != nullptr)
                {
                    nodeQueue.push(prev->left);
                }
                if (prev->right != nullptr)
                {
                    nodeQueue.push(prev->right);
                }
                nodeQueue.pop();
                if (i != size - 1)
                {
                    Node *next = nodeQueue.front();
                    prev->next = next;
                }
                else
                {
                    prev->next = nullptr;
                }
            }
        }
        return root;
    }
};
// @lc code=end

