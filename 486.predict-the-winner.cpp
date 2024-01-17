/*
 * @lc app=leetcode id=486 lang=cpp
 *
 * [486] Predict the Winner
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // 粗暴的方法：递归
    //  优化的方法：动态规划
    bool predictTheWinner(vector<int>& nums) {
        //定义dp[i][j]为净胜分
        //dp[i][j] = max(nums[i] - dp[i+1][j],  num[j] - dp[i][j-1]) ?;
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = 0; i <n; i++){
            dp[i][i]= nums[i];
        }
        for(int i = n-2; i >= 0; i--){
            for(int j = i+1; j < n; j++){
                dp[i][j] = max((nums[i] -dp[i+1][j]), (nums[j] - dp[i][j-1]));
            }
        }
        return dp[0][n-1] >= 0;
    }
};
// @lc code=end

