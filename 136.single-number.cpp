/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        int res = nums[0];
        for(int i = 1 ; i < nums.size(); i++){
            res = res ^ nums[i];
        }
        return res;
    }
};
// @lc code=end

