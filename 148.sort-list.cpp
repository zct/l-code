/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
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
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast->next != nullptr && fast->next->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *bHead = slow->next;
        slow->next = nullptr;
        cout << head->val << endl;
        ListNode* aList = sortList(head);
        ListNode* bList = sortList(bHead);
        ListNode* res = mergeList(aList, bList);
        return res;
    }

    ListNode* mergeList(ListNode* aHead, ListNode* bHead){
        ListNode* dummyNode = new(ListNode);
        ListNode *head = dummyNode;
        while(aHead != nullptr && bHead != nullptr){
            if(aHead->val < bHead->val){
                dummyNode->next = aHead;
                aHead = aHead->next;
            } else {
                dummyNode->next = bHead;
                bHead = bHead->next;
            }
            dummyNode = dummyNode->next;
        }
        if(aHead){
            dummyNode->next = aHead;
        } else {
            dummyNode->next = bHead;
        }
        return head->next;
    }
};
// @lc code=end

