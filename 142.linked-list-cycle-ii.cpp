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

//推导公式
// 2*f = l
// k+m+f1*n = 2*(k+m+l1*n)
//k是环的起点到head的距离，m是相遇点到环起点的距离
// k+m = n*x
//所以从起点和m点同时开始走，必定能够相遇在环的起点
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

