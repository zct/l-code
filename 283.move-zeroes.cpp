/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //数字前面0的个数
        int numZero  = 0;
        for(int  i = 0 ; i < nums.size(); i++){
            if(nums[i] == 0){
                numZero++;
            } else {
                nums[i-numZero] = nums[i];
            }
        }
        for(int i = 1; i <= numZero; i++){
            nums[nums.size() - i] = 0;
        }
        
    }
};
// @lc code=end

