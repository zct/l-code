/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //最大堆
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> max_heap(nums.begin(), nums.end());
        for(int i = 1; i < k; i++){
            max_heap.pop();
        }
        return max_heap.top();
    }
};
// @lc code=end

