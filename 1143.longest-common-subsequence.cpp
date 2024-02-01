/*
 * @lc app=leetcode id=1143 lang=cpp
 *
 * [1143] Longest Common Subsequence
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //动态规划？
    //dp[i][j] = dp[i-1][j-1] + 1;
    //动态规划的方程自己想
    //dp[i][j] 代表s[i-1][j-1] 是为了不用特殊处理dp[0][0]
    //这个转换方程不是代表以s[i-1] s[j-1]结尾的子串
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        if (n1 == 0 || n2 == 0){
            return 0;
        }
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        for(int i = 1; i <= n1; i++){
            for(int j = 1; j <= n2; j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n1][n2];
    }
};
// @lc code=end

