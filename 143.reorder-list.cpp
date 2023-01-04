/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        //
        while(fast->next != nullptr && fast->next->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* halfR = reverse(slow->next);
        slow->next = nullptr;
        cout << slow->val << endl;
        while(head != nullptr && halfR != nullptr){
            ListNode* aNext = head->next;
            ListNode* bNext = halfR->next;
            head->next = halfR;
            halfR->next = aNext;
            head = aNext;
            halfR = bNext;
        }
        return;
    }

    ListNode* reverse(ListNode* head){
        if(head == nullptr){
            return nullptr;
        }
        ListNode* prev = nullptr;
        ListNode *curr = head;
        ListNode *next = curr->next;
        while(next != nullptr){
            curr->next = prev;
            prev = curr;
            curr = next;
            next = next->next;
        }
        curr->next = prev;
        return curr;
    }
};
// @lc code=end

