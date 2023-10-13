/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
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

class Solution {
public:
    ListNode* reversalList(ListNode* head){
        if(head == nullptr){
            return nullptr;
        }
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr != nullptr){
            ListNode * next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head == nullptr){
            return false;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast->next != nullptr && fast->next->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = reversalList(slow->next);
        ListNode* halfBegin = slow->next;
        ListNode* begin = head;
        while(halfBegin != nullptr){
       // cout << begin->val << "|" << halfBegin->val << endl;
            if(begin->val != halfBegin->val){
                return false;
            } else {
                begin = begin->next;
                halfBegin = halfBegin->next;
            }
        }
        return true;
        
    }
};
// @lc code=end

