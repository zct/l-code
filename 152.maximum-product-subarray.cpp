/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //动态规划
    //以什么结尾的
    //maxdp[i] = max(maxdp[i-1] * nums[i],  minddp[i-1] * nums[i]
    //mindp[i] = min(mindp[i-1] * nums[i], maxdp[i-1] * nums[i])
    int maxProduct(vector<int>& nums) {
        vector<int> maxDP(nums.size(), 0);
        vector<int> minDP(nums.size(), 0);
        maxDP[0] =  nums[0]; 
        minDP[0] =  nums[0];
        int ans = maxDP[0];
        for(int i = 1; i < nums.size(); i++){
            maxDP[i] = max(maxDP[i-1] * nums[i], minDP[i-1] * nums[i]);
            maxDP[i] = max(maxDP[i], nums[i]);
            minDP[i] = min(minDP[i-1] * nums[i], maxDP[i-1] * nums[i]);
            minDP[i] = min(minDP[i], nums[i]);
            ans = max(maxDP[i], ans);
        }
        return ans;
        
    }
};
// @lc code=end

