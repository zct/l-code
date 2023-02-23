/*
 * @lc app=leetcode id=673 lang=cpp
 *
 * [673] Number of Longest Increasing Subsequence
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //需要保存两个状态
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int> > dp(n, vector<int>(2, 1));
        set<int> longIndex;
        int curLen = 1;
        for(int i = 1; i< n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    if(dp[j][0] + 1 > dp[i][0]){
                        dp[i][0] = dp[j][0] + 1;
                        dp[i][1] = dp[j][1];
                    } else if(dp[j][0] +1 == dp[i][0]){
                        dp[i][1] += dp[j][1];
                    }
                    if(dp[i][0] > curLen){
                        curLen = dp[i][0];
                        longIndex.clear();
                        longIndex.insert(i);
                    } else if(dp[i][0] == curLen){
                        longIndex.insert(i);
                    }
                }
            }
        }
        if(curLen == 1){
            return n;
        }
        int res = 0;
        for(auto i:longIndex){
            res += dp[i][1];
        }
        return res;
    }
};
// @lc code=end

