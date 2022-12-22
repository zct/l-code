/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //dp[n] = dp[i-1]dp[i+1...n]
    int numTrees(int n) {
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        dp[0] = 1;
        for(int i = 2 ; i <= n; i++){
            for(int j = 0; j <i; j++ ){
                dp[i] = dp[i]  + dp[j]*dp[i-j-1];
            }
        }
    return dp[n];
    }
};
// @lc code=end

