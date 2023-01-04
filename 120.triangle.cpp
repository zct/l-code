/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(2, vector<int>(triangle.size(), 0));
        dp[0][0] = triangle[0][0];
        for(int i = 1; i < triangle.size(); i++){
            for(int j = 0; j <= i; j++){
                if(j == i){
                    dp[i%2][j] = triangle[i][j] + dp[(i+1)%2][j-1];
                } else if(j == 0){
                    dp[i%2][j] = triangle[i][j] + dp[(i+1)%2][0];
                } else {
                    dp[i%2][j] = min(triangle[i][j] + dp[(i+1)%2][j-1],
                    triangle[i][j] + dp[(i+1)%2][j]);
                }
            }
        }
        int res = dp[(triangle.size()-1)%2][0];
        for(int i = 0; i < triangle.size(); i++){
            res = min(dp[(triangle.size()-1)%2][i], res);
        }
        return res;
    }
};
// @lc code=end

