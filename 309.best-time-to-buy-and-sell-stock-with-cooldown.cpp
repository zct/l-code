/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //动态规划
    //0 持有 
    //1 不持有 不可买入
    //2 不持有 可买入
    //dp[i][0] = max(dp[i-1][1], dp[i-1][2] - prices[i])
    //dp[i][1] = dp[i-1][0] + prices[i-1]
    //dp[i][2] = max(dp[i-1][2], dp[i-1][1]);
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 0){
            return 0;
        }
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(3, 0));
        dp[0][0] = -1 * prices[0];
        dp[0][1] = 0;
        dp[0][2] = 0;
        for(int i = 1; i < n; i++){
            dp[i][0] = max(dp[i-1][0], dp[i-1][2] - prices[i]);
            dp[i][1] = dp[i-1][0] + prices[i];
            dp[i][2] = max(dp[i-1][2], dp[i-1][1]);
        }
        return max(dp[n-1][1], dp[n-1][2]);
    }
};
// @lc code=end

