/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1)
            return 0;
        int begin = 0;
        int end = nums.size()-1;
        int index = (end+begin)/2;
        while(index >=begin && index <= end){
            if(index == 0)  {
                if(nums[index] > nums[index+1])
                    break;
            } else if(index == nums.size()-1){
                if(nums[index] > nums[index-1])
                    break;
            } else if(nums[index] > nums[index -1] && nums[index] > nums[index+1]){
                break;
            }
            if(index != nums.size() -1 && nums[index+1] > nums[index]){
                begin = index+1;
            } else if(index != 0 && nums[index-1] > nums[index]){
                end = index-1;
            }
            index = (end+begin)/2;
        }
        return index;
    }
};
// @lc code=end

