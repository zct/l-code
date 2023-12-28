/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    //第一件偷,则在[0, n-2]区间上
    //第一件不偷，则在[1, n-1]区间上
    int rob(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        if(nums.size() == 1){
            return nums[0];
        }
        vector<int> dp(nums.size(), 0);
        //第一间偷
        int res = 0;
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i = 2; i < nums.size()-1; i++){
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        res = dp[nums.size() -2];
        //第一间不偷
        dp[0] = 0;
        dp[1] = nums[1];
        for(int i = 2; i < nums.size(); i++){
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        return max(res, dp[nums.size() -1]);
    }
};
// @lc code=end

