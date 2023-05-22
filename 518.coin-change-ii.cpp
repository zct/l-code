/*
 * @lc app=leetcode id=518 lang=cpp
 *
 * [518] Coin Change II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int change(int amount, vector<int>& coins) {
        map<int, bool> coinMap;
        for(auto& coin : coins){
            coinMap[coin] = true;
        }
        
        vector<int> dp(amount+1 ,0);
        dp[0] = 1;
        for(int i = 0; i < coins.size(); i++){
            for(int j = coins[i] ; j <= amount; j++){
                dp[j] += dp[j-coins[i]];
            }
        }
        return dp[amount];

    }
private:
    int count;
};
// @lc code=end

