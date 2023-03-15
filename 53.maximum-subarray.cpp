/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = 0;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if( i > 0){
            res = max(sum, res);
            } else {
                res = sum;
            }
            if(sum < 0){
                sum = 0;
            }
        }
        return res;
    }
};
// @lc code=end

