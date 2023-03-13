/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        vector<vector<int> > dp(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++){
            dp[i][i] = 1;
        }
        int maxStr = 1;
        int begin = 0;
        for(int j = 0 ;  j < n; j++){
            for(int i = j-1; i>=0; i--){
                if(s[i] == s[j]){
                    if(j == i+1){
                        dp[i][j] = 2;
                        if(maxStr < 2){
                            begin = i;
                            maxStr = 2;
                        }
                    } else if (dp[i+1][j-1] > 0) {
                        dp[i][j] = dp[i+1][j-1]+2;
                        if(dp[i][j] > maxStr){
                            begin = i;
                            maxStr = dp[i][j];
                        }
                    }

                } else {
                    dp[i][j] = 0;
                }
            }
        }
        return s.substr(begin, maxStr);
    }
};
// @lc code=end
