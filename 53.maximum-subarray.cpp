/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //dp[i] = max(dp[i-1]+nums[i], nums[i])
    //return max(dp[0..i]);
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        int ans = dp[0];
        for(int i = 1; i < nums.size(); i++){
            dp[i] = max(dp[i-1] + nums[i], nums[i]);
            ans = max(dp[i], ans);
        }
        return ans;
    }
    int maxSubArray2(vector<int>& nums) {
        int res = 0;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if( i > 0){
            res = max(sum, res);
            } else {
                res = sum;
            }
            if(sum < 0){
                sum = 0;
            }
        }
        return res;
    }
};
// @lc code=end

