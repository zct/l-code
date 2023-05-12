/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
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
    //假设x在链表中一定存在
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr){
            return head;
        }
        ListNode* tNode = head;
        ListNode* iNode = new(ListNode);
        iNode->next = head;
        ListNode* fakeHead = iNode;
        while(tNode != nullptr && tNode->val < x ){
            tNode = tNode->next;
            iNode = iNode->next;
        }
        ListNode* prev = iNode;
        //cout <<  "prev"<< prev->val << endl;
        //cout <<"iNode"<< iNode->val << endl;
        while(tNode != nullptr){
            if(tNode->val < x){
                //cout << tNode->val << endl;
                //cout << prev->val << endl;
                //del
                prev->next = tNode->next;
                //insert
                ListNode *temp = iNode->next;
                iNode->next = tNode;
                tNode->next = temp;
                //set iNode ;
                iNode = iNode->next;
                //set tNode
               tNode = prev->next;
            } else {
                tNode = tNode->next;
                prev = prev->next;
            }
        }
        return fakeHead->next;
    }
};
// @lc code=end

