/*
 * @lc app=leetcode id=581 lang=cpp
 *
 * [581] Shortest Unsorted Continuous Subarray
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //
    // 三段的写法没有看懂
    // 找最右边界，然后在找左边界
    // 双指针然后再调整的写法看懂了
    int findUnsortedSubarray(vector<int>& nums) {
        int begin = 0;
        int end = 0; 
        int n = nums.size();
        int maxValue = nums[0];
        int minValue = nums[n-1];
        for(int i = 0; i < n; i++){
            if(nums[i] < maxValue){
                end = i;
            } else if(nums[i] > maxValue){
                maxValue = nums[i];
            }
        }
        for(int i = n-1; i >= 0; i--){
            if(nums[i] > minValue){
                begin = i;
            } else if(nums[i] < minValue){
                minValue = nums[i];
            }
        }
        if(end == begin){
            return 0;
        }
        return end-begin+1;
    }
};
// @lc code=end

