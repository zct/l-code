/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    //这个动态规划不是最优解
    //考虑贪心算法
    bool canJumpa2(vector<int>& nums) {
        vector<bool> f(nums.size());
        for(auto iter = f.begin(); iter != f.end(); iter++){
            *iter = false;
        }
        f[0] = true;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = 1 ; j <= nums[i]; j++ ){
                if(i+j < nums.size()) {
                    f[i+j] =  f[i+j] || f[i];
                }
                if(f[nums.size() -1]){
                    break;
                }
            }
        }
        return f[nums.size() -1];
    }
    //更新最远可到达的位置
    //如果大于，则更新
    bool canJump(vector<int>& nums) {
        bool res = false;
        int maxIndex = 0;
        for(int i = 0; i < nums.size(); i++){
            if(i <= maxIndex){
                maxIndex = max(maxIndex, i+nums[i]);
                if(maxIndex >= nums.size()-1){
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end

