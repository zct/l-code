/*
 * @lc app=leetcode id=445 lang=cpp
 *
 * [445] Add Two Numbers II
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = rotateList(l1);
        l2 = rotateList(l2);
        ListNode *temp = l1;
        bool addOne = false;
        ListNode* l1Prev = nullptr;
        ListNode *head = l1;
        while(l1 != nullptr && l2 != nullptr){
            int val = l1->val + l2->val;
            if(addOne){
                val += 1;
            }
            if(val >= 10){
                addOne = true;
                val = val%10;
            } else {
                addOne = false;
            }
            l1->val = val; 
            l1Prev = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 != nullptr){
            if(addOne){
                l1->val += 1;
            }
            if(l1->val >= 10){
                addOne = true;
                l1->val = l1->val % 10;
            } else {
                addOne = false;
            }
            l1Prev = l1;
            l1 = l1->next;
        }
        while(l2 != nullptr){
            if(addOne){
                l2->val +=1;
            }
            if(l2->val >= 10){
                addOne = true;
                l2->val = l2->val % 10;
            } else {
                addOne = false;
            }
            l1Prev->next = l2;
            l2 = l2->next;
            l1Prev = l1Prev->next;
        }
        if(addOne){
            ListNode* a = new(ListNode);
            a->val = 1;
            l1Prev->next = a;
        }
        return rotateList(head);
    }
    
    ListNode* rotateList(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* cur = head;
        while(cur != nullptr){
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};
// @lc code=end

