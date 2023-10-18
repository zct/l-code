/*
 * @lc app=leetcode id=237 lang=cpp
 *
 * [237] Delete Node in a Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <bits/stdc++.h>
class Solution {
public:
    //修改后面链表的值,删除最后一个元素
    void deleteNode(ListNode* node) {
        ListNode* prev = node;
        ListNode* curr = node->next;
        while(curr->next != nullptr){
            prev->val = curr->val;
            prev = prev->next;
            curr = curr->next;
        }
        prev->val = curr->val;
        prev->next = nullptr;
    }
};
// @lc code=end

