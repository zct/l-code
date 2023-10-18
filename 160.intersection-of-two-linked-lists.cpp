/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
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
    int getListLen(ListNode* head){
        int len = 0;
        while(head != nullptr){
            len++;
            head = head->next;
        }
        return len;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int aLen = getListLen(headA);
        int bLen = getListLen(headB);
        ListNode *res = nullptr;
        ListNode *aCur = headA;
        ListNode *bCur = headB;
//        if(aLen == 0 || )
        if(aLen > bLen){
            for(int i = 0 ; i < (aLen-bLen); i++){
                aCur = aCur->next;
            }
        } else if(aLen < bLen){
            for(int i = 0; i < (bLen-aLen);i++){
                bCur = bCur->next;
            }
        }
        while(aCur != nullptr && bCur != nullptr){
            if(aCur == bCur){
                res = aCur;
                break;
            }
            aCur = aCur->next;
            bCur = bCur->next;
        }
        return res;
    }
};
// @lc code=end

