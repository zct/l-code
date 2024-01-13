/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit2(vector<int>& prices) {
        int profit = 0;

        for(int i = 1; i < prices.size(); i++){
            if(prices[i] > prices[i-1]){
                profit += (prices[i] - prices[i-1]);
            }
        }
        return profit;
        
    }

    //动态规划的思路
    //0 不持有
    //1 持有

    //dp[i][0] = max(dp[i-1][1] + prices[i], dp[i-1][0])
    //dp[i][1] = max(dp[i-1][0] - prices[i], dp[i-1][1])
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n <= 0){
            return 0;
        }
        vector<vector<int> > dp(n , vector<int>(2, 0));
        dp[0][0] = 0;
        dp[0][1] = -1 * prices[0];
        for(int i = 1; i < n; i++ ){
            dp[i][0] = max(dp[i-1][1] + prices[i], dp[i-1][0]);
            dp[i][1] = max(dp[i-1][0] - prices[i], dp[i-1][1]);
        }
        return dp[n-1][0];
    }

};
// @lc code=end

