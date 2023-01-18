/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int begin = 0;
        int end = nums.size()-1;
        while(begin < end){
            if(begin  == end -1){
                return nums[begin] < nums[end]? nums[begin]:nums[end];
            }
            if(nums[end] < nums[begin]){
                begin = (end+begin)/2 ;
            } else {
                end = begin;
                begin = 0;
            }
        }
        return nums[begin];
    }
};
// @lc code=end

