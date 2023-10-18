/*
 * @lc app=leetcode id=328 lang=cpp
 *
 * [328] Odd Even Linked List
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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *evenCurr = head->next;
        ListNode* evenHead = evenCurr;
        ListNode *oddCurr = head;
        ListNode *curr = evenCurr->next;
        while(curr != nullptr){
            if(curr->val % 2 == 0){
                evenCurr->next = curr;
                evenCurr = curr;
            } else {
                oddCurr->next = curr;
                oddCurr = curr;
            }
            curr= curr->next;
        }
        evenCurr->next = nullptr;
        oddCurr->next = evenHead;
        return head; 
    }
};
// @lc code=end

