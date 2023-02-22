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
    //dp
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int longNum = 1;
        int curLen = 1;
        for(int i = 1; i< n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[j]+1, dp[i]);
                    if(dp[i] > curLen){
                        longNum = 1;
                        curLen = dp[i];
                    } else if(dp[i] == curLen){
                        longNum++;
                    }
                }
            }
        }
        if(curLen == 1){
            return n;
        }
        return longNum;
    }
};
// @lc code=end

