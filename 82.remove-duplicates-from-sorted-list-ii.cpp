/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr){
            return nullptr;
        }
        ListNode* prev = new(ListNode);
        ListNode *ret = prev;
        prev->next = head;
        ListNode* cur = head;
        ListNode* next = head->next;
        bool isSame = false;
        while(next != nullptr){
            if(next->val == cur->val){
                cur = next;
                next = next->next;
                isSame = true;
            } else {
                if(isSame){
                    prev->next = next;
                    cur = next;
                    next= next->next;
                } else {
                    prev = cur;
                    cur = next;
                    next = next->next;
                }
                isSame = false;
            }
        }
        if(isSame){
            prev->next = next;
        }
        return ret->next;
    }
};
// @lc code=end

