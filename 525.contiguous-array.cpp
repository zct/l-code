/*
 * @lc app=leetcode id=525 lang=cpp
 *
 * [525] Contiguous Array
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
//前缀和
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                dp[i][i] = -1;
            } else {
                dp[i][i] = 1;
            }
        }
        for(int i = 0; i < n; i++){
            for(int j =i+1; j < n ; j++){
                if(nums[j] == 0){
                    dp[i][j] = dp[i][j-1] -1;
                } else {
                    dp[i][j] = dp[i][j-1]+ 1;
                }
                if(dp[i][j] == 0){
                    res = max(res, j-i+1);
                }
            }
        }
        return res;
    }
};
// @lc code=end

