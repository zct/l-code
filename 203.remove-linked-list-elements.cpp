/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* fakeHead = new(ListNode);
        fakeHead->next = head;
        ListNode* prev = fakeHead;
        ListNode* cur = head;
        while(cur != nullptr){
            if(cur->val == val){
                prev->next = cur->next;
            } else {
                prev = prev->next;
            }
            cur = cur->next;
        }
        return  fakeHead->next;
    }
};
// @lc code=end

