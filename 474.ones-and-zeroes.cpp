/*
 * @lc app=leetcode id=474 lang=cpp
 *
 * [474] Ones and Zeroes
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;

int zeroCount(string str){
    int count = 0;
    for(int i = 0; i < str.size(); i++){
        if(str[i] == '0'){
            count++;
        }
    }
    return count;
}

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> innerVec(m+1, vector<int>(n+1, 0));
        vector<vector<vector<int> > > dp(strs.size(), innerVec);
        for(int i = 0; i < strs.size(); i++){
            int count_0 = zeroCount(strs[i]);
            int count_1 = strs[i].size() - count_0;
            for(int j = 0; j <= m; j++){
                for(int k = 0; k <= n; k++){
                    if(j >= count_0 && k >= count_1){
                        if(i == 0){
                        dp[i][j][k] =  1;
                        } else {
                       dp[i][j][k] = max(dp[i-1][j][k], dp[i-1][j-count_0][k-count_1]+1);
                        }
                    } else {
                        if(i != 0)
                        dp[i][j][k] = dp[i-1][j][k];
                    }
                }
            }
        }
        return dp[strs.size()-1][m][n];

    }
};
// @lc code=end

