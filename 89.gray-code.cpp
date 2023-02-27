/*
 * @lc app=leetcode id=89 lang=cpp
 *
 * [89] Gray Code
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //use dp
    vector<int> grayCode(int n) {
        vector<int>  dp(1, 0);
        for(int i = 1; i <= n; i++){
            for(int j = dp.size()-1; j >=0; j--){
                int t = 1<< (i-1);
                dp.push_back(t+dp[j]);
            }
        }
        return dp;
    }
};
// @lc code=end

