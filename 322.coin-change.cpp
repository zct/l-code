/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0){
            return 0;
        }
        this->coins = coins;
        this->amount = amount;
        map<int, bool> coinMap;
        for(auto c : coins){
            coinMap[c] = false;
        }
        vector<int> dp(amount+1, -1);
        dp[0] = 0;
        for(int i = 1; i <= amount; i++){
            for(auto iter = coinMap.begin(); iter != coinMap.end(); iter++){
                if(i - iter->first >=0 && dp[i-iter->first] >= 0 ){
                    dp[i] =  dp[i] == -1 ? dp[i-iter->first]+1:min(dp[i], dp[i-iter->first]+1);
                } 
            }
        }
        
        return dp[amount];
        
    }
    private:
        vector<int> coins;
        long amount;
        long res;
};
// @lc code=end

