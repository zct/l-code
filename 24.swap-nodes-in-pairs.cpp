/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr){
            return nullptr;
        }
        ListNode* fakeHead = new(ListNode);
        fakeHead->next = head;
        ListNode* prev = fakeHead;
        ListNode* cur = head;
        ListNode* next = cur->next;
        while(next != nullptr){
            ListNode *t = next->next;
            prev->next = next;
            next->next = cur;
            cur->next = t;
            prev = cur;
            cur = t;
            if(t != nullptr){
                next = t->next;
            } else {
                next = nullptr;
            }
        }
        return fakeHead->next;
    }
};
// @lc code=end

