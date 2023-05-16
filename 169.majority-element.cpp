/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //摩尔投票法
    //有一道类似的题目，类似按位异或计算出来的？
    //一个数组中其他元素都出现了两次，只有一个元素出现了一次
    int majorityElement(vector<int>& nums) {
        int num = nums[0];
        int count = 1;
        for(int i= 1; i < nums.size(); i++){
            if(count <= 0){
                num = nums[i];
            }
            if(nums[i] == num){
                count++;
            } else {
                count--;
            }
        }
        return num;
    }
};
// @lc code=end

