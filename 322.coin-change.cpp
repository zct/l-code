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
        this->res  = -1;
        sort(this->coins.begin(), this->coins.end());
        backtracking(0, 0);
        return this->res;
        
    }
    void backtracking(long num, long curSum){
        for(int i = this->coins.size()-1; i >= 0; i--){
            if(curSum + this->coins[i] < this->amount){
                num++;
                if(this->res != -1 && num > this->res){
                    return;
                }
                backtracking(num, curSum + this->coins[i]);
                num--;
            }
            if(curSum + this->coins[i] == this->amount){
                this->res = this->res == -1? num+1:min(this->res, num+1); 
                return;
            }
        }
    }
    private:
        vector<int> coins;
        long amount;
        long res;
};
// @lc code=end

