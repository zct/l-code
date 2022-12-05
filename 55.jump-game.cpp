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
    bool canJump(vector<int>& nums) {
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
};
// @lc code=end

