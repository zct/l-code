/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0){
            return 0;
        }
        int minPrice = prices[0];
        int res = 0;
        for(auto i :prices){
            minPrice = min(minPrice,i);
            res = max(res, i - minPrice);
        }
        return res;
    }
};
// @lc code=end

