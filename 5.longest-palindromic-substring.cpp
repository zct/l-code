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
    string longestPalindrome2(string s) {
        if(s.size() == 0){
            return "";
        }
        int len = 1;
        int resBegin = 0;
        for(int middle = 0 ; middle < s.size() -1; middle++){
            int begin = middle ;
            int end = middle ;
            while(begin >= 0 && end < s.size()){
                if(s[begin] == s[end]){
                    if((end - begin +1) > len){
                        len = end - begin +1;
                        resBegin = begin;
                    }
                    begin--;
                    end++;
                } else {
                    break;
                }
            }
             begin = middle;
            end = middle +1;
            while(begin >= 0 && end < s.size()){
                if(s[begin] == s[end]){
                    if((end - begin +1) > len){
                        len = end - begin +1;
                        resBegin = begin;
                    }
                    begin--;
                    end++;
                } else {
                    break;
                }
            }
        }
        return s.substr(resBegin, len);
    }
    //遍历方向
    //dp[i][j] = dp[i+1][j-1] + 2 (if s[i] == s[j])
    string longestPalindrome(string s){
        int n = s.size();
        string res;
        int maxLen = 0;
        vector<vector<int> > dp(n, vector<int>(n, 0));
        for(int i = 0;i < n; i++){
            dp[i][i] = 1;
        }
        for(int i = n-1; i >= 0; i--){
            for(int j = i; j< n; j++){
                if(s[i] == s[j]) {
                    if(j -i < 2){
                        dp[i][j] = 1;
                    } else if(dp[i+1][j-1]){
                        dp[i][j] = 1;
                    }
                if(dp[i][j]){
                int len = j - i + 1;
                if(len > maxLen){
                    res = s.substr(i, len);
                    maxLen = len;
                }
                }
                }
            }
        }
        return res;
    }
    
    string longestPalindrome1(string s)
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
