/*
 * @lc app=leetcode id=97 lang=cpp
 *
 * [97] Interleaving String
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int s1Len = s1.size();
        int s2Len = s2.size();
        if(s1Len + s2Len != s3.size()){
            return false;
        }
        //dfs(0, 0, 0);
        vector<vector<bool>> dp(s1Len+1, vector<bool>(s2Len+1, false));
        dp[0][0] = true;
        for(int i = 0; i <= s1Len; i++){
            for(int j = 0; j <= s2Len; j++){
            if(i == 0 && j == 0){
                dp[0][0] = true;
            } else if(j == 0){
                for(int i = 1; i <= s1Len; i++){
                    dp[i][0] = s1[i-1] == s3[i-1] && dp[i-1][0];
                }
            } else if(i == 0){
                for(int j = 1; j <= s2Len; j++){
                    dp[0][j] = s2[j-1] == s3[j-1] && dp[0][j-1];
                }
            } else {
                if(s1[i-1] == s3[i+j-1]){
                    dp[i][j] = dp[i][j] || dp[i-1][j];
                }
                if(s2[j-1] == s3[i+j-1]){
                    dp[i][j] = dp[i][j] || dp[i][j-1];
                }
            }

            }
        }
        return dp[s1Len][s2Len];
    }

   //time limit exceeed 
    void dfs(int s1Index, int s2Index, int s3Index){
        if(s3Index == s3.size()){
            this->res = true;
            return;
        }
        if(s1Index == s1.size()){
            if(s2[s2Index] != s3[s3Index]){
                return ;
            } else {
                dfs(s1Index, s2Index+1, s3Index+1);
            }
        } else if(s2Index == s2.size()){
            if(s1[s1Index] != s3[s3Index]){
                return ;
            } else {
                dfs(s1Index+1, s2Index, s3Index +1);
            }
        } else {
            if(s1[s1Index] == s3[s3Index]){
                dfs(s1Index+1, s2Index, s3Index+1);
            }
            if(s2[s2Index] == s3[s3Index]){
                dfs(s1Index, s2Index+1, s3Index+1);
            }
            return;
        }
        
    }

private:
    string s1;
    string s2;
    string s3;
    bool res;
    
};
// @lc code=end

