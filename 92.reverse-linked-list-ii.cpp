/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
 */

// @lc code=start

#include <iostream>

using namespace std;

/*struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};*/

class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (head == NULL || head->next == NULL || left == right)
        {
            return head;
        }
        ListNode FakeHead(0, NULL);
        FakeHead.next = head;
        ListNode *begin = &FakeHead;
        ListNode *end = head;

        for (auto i = 1; i < left; i++)
        {
            begin = begin->next;
        }
        for (auto i = 1; i < right; i++)
        {
            end = end->next;
        }

        ListNode *tBegin = begin;
        ListNode *tNext = begin->next;
        ListNode *tEnd = end->next;
        while (tNext != tEnd)
        {
            ListNode *temp = tNext->next;
            tNext->next = tBegin;
            tBegin = tNext;
            tNext = temp;
        }
        begin->next->next = tEnd;
        begin->next = end;

        return FakeHead.next;
    }
};

/*int main()
{
    ListNode head = ListNode(1, NULL);
    ListNode L2 = ListNode(2, NULL);
    ListNode L3 = ListNode(3, NULL);
    ListNode L4 = ListNode(4, NULL);
    ListNode L5 = ListNode(5, NULL);
    head.next = &L2;
    L2.next = &L3;
    L3.next = &L4;
    L4.next = &L5;
    Solution s;
    s.reverseBetween(&head, 2, 4);
    ListNode *temp = &head;
    while (temp != NULL)
    {
        cout << temp->val << endl;
        temp = temp->next;
    }
}*/
// @lc code=end
