/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
#define L_INT_MAX 1 << 31
class Solution {
public:
    //初步想法是和3sum一样，直接滑动扫描，找到最小值
    //需要考虑剪枝的问题，提前终止里面的循环？
    int threeSumClosest(vector<int>& nums, int target) {
        int res = __INT_MAX__;
        int ret = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            int j = i+1;
            int k = nums.size() - 1;
            while(j < k){
                int sum = nums[i] + nums[j];
                sum += nums[k];
                if(sum == target){
                    res = 0;
                    ret = target;
                    break;
                } else if(sum < target){
                    if(abs(sum - target ) < res){
                        ret = sum;
                    }
                    res = min(res, abs(sum - target));
                    j++;
                } else{
                    if(abs(sum - target) > res){
                        break;
                    }
                    if(abs(sum - target) < res){
                        ret = sum;
                    }
                    res = min(res, abs(sum - target));
                    k--;
                }
            }
        }
        return ret;
    }
};
// @lc code=end

