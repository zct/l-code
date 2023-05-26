/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //错误的解法:两个指针分别从begin和end开始
    //正确的解法，两个指针都从begin开始
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int begin = 0;
        int end = 0;
        sum = nums[0];
        int res = 0;
        while(begin <= end && end < nums.size()){
            if(sum >= target){
                res = (res == 0)? end-begin+1 : min(res, end-begin+1);
                sum -= nums[begin++];
            } else {
                end++;
                if(end >= nums.size()){
                    break;
                }
                sum+= nums[end];
            }
        }
        return res;
    }
};
// @lc code=end

