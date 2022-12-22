/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //怎么想出动态规划?
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1, false);
        map<string, int> wordCount;
        for(auto str: wordDict){
            wordCount[str]++;
        }
        dp[0] = true;
        for(int i = 1; i<= s.size(); i++){
            for(int j = i-1; j >=0; j--){
                if(wordCount[s.substr(j, i-j)] != 0){
                    dp[i] = dp[i] || dp[j];
                }
            }
        }
        return dp[s.size()];
    }
};
// @lc code=end

