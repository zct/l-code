/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
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
        ListNode* rl1 = l1;
        ListNode* rl2 = l2;
        ListNode *prevL1 = nullptr;
        ListNode *prevL2 = nullptr;

        ListNode* addHead = rl1;
        bool add = false;
        while(rl1 != nullptr && rl2 != nullptr) {
            rl1->val += rl2->val;
            if(add){
                rl1->val += 1;
                add = false;
            }
            if(rl1->val >= 10){
                add = true;
                rl1->val = rl1->val % 10;
            }
            prevL1 = rl1;
            prevL2 = rl2;
            rl1 = rl1->next;
            rl2 = rl2->next;
        }
        if(rl2 != nullptr){
            prevL1->next = rl2;
            rl1 = rl2;
        }
        while(add == true && rl1 != nullptr){
                rl1->val +=1;
                if(rl1->val >= 10){ 
                    rl1->val = rl1->val % 10;
                    add = true;
                }else {
                    add = false;
                }
                if(rl1->next == nullptr && add){
                    rl1->next = new(ListNode);
                    rl1->next->val = 1;
                    add = false;
                }
                rl1 = rl1->next;
        }
        if(add){
            prevL1->next = new(ListNode);
                    prevL1->next->val = 1;
        }
        return addHead;
       // return reverseList(addHead);
    }
    
    ListNode* reverseList(ListNode* l){
        ListNode *prev = nullptr;
        ListNode* cur = l;
        ListNode* next = l->next;
        while(next != nullptr){
            cur->next = prev;
            ListNode* t = cur;
            cur = next;
            prev = t;
            next = next->next;
        }
        cur->next = prev;
        return cur;
    }
};
// @lc code=end

