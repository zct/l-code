/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
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
    ListNode *detectCycle(ListNode *head) {

        ListNode *slow = head;
        ListNode *fast = head;
        bool isCycle = true;
        while(true){
            if(slow == nullptr || fast == nullptr || fast->next == nullptr){
                isCycle = false;
                break;
            }
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                break;
            }
        }
        if(!isCycle) return nullptr;
        
        ListNode *begin = head;
        while(begin != fast){
            begin = begin->next;
            fast = fast->next;
        }
        return begin;
        
        
    }
};
// @lc code=end

