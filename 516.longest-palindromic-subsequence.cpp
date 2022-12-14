/*
 * @lc app=leetcode id=516 lang=cpp
 *
 * [516] Longest Palindromic Subsequence
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int> > dp{s.size(), vector<int>(s.size(),0)};
        for(int i = 0; i < s.size(); i++){
            dp[i][i] = 1;
        }
        for(int d = 1; d < s.size(); d++){
            for(int i = 0; i < s.size(); i++){
                if(i+d < s.size()){
                    if(s[i] == s[i+d]){
                        dp[i][i+d] = dp[i+1][i+d-1] + 2;
                    } else {
                        dp[i][i+d] = max(dp[i+1][i+d], dp[i][i+d-1]);
                    }
                }
            }
        }
        return dp[0][s.size()-1];
    }
};
// @lc code=end

