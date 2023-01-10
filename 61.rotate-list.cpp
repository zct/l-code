/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* probe = head;
        int listSize = 0;
        while(probe != nullptr){
            probe = probe->next;
            listSize++;
        }
        if (listSize == 0){
            return head;
        }
        k  = k % listSize;
        if(k == 0){
            return head;
        }
        int index = listSize -k;
        probe = head;
        int i = 1;
        while(i++ < index){
            probe = probe->next;
        }
        ListNode* res = probe->next;
        probe->next = nullptr;
        ListNode* end = res;
        while(end->next != nullptr){
            end = end->next;
        }
        end->next = head;
        return res;
    }
};
// @lc code=end

