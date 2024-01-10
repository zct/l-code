/*
 * @lc app=leetcode id=718 lang=cpp
 *
 * [718] Maximum Length of Repeated Subarray
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //利用动态规划的思路来做
    //dp[i][j] = dp[i+1][j+1] + 1;
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int aSize = nums1.size();
        int bSize = nums2.size();
        if(aSize == 0 || bSize == 0){
            return 0;
        }
        vector<vector<int>> dp(aSize, vector<int>(bSize, 0));
        int res = 0;
        for(int i = aSize-1; i >= 0; i--){
            for(int j = bSize-1; j >= 0; j--){
                if(nums1[i] == nums2[j]){
                    if(i == aSize -1 || j == bSize -1){
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = dp[i+1][j+1] +1;
                        res = max(dp[i][j], res);
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end

