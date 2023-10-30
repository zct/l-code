/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 */

// @lc code=start
#include <bits/stdc++.h>
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        prefixSum.resize(nums.size(), 0);
        int res = 0;
        int sum = 0;
        for(int i = 0;  i < nums.size(); i++){
            sum += nums[i];
            prefixSum[i] = sum;
            if(sum == k){
                res++;
            }
        }
        int begin = 0;
        for(int j = begin+1; j  < nums.size(); j++){
            //更新prefixsum里面的数值
            for(int z = j; z < nums.size(); z++){
                prefixSum[z] -= nums[begin];
                if(prefixSum[z] == k){
                    res++;
                }
            }
            begin++;
        }
        return res;
    }
private:
    vector<int> prefixSum;
};
// @lc code=end

