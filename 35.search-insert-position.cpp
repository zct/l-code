/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int begin = 0;
        int end = nums.size() -1;
        while(begin < end){
            int middle =  (begin+end)/2;
            if(nums[middle] > target ){
                end = middle -1;
            } else if(nums[middle] == target){
                return middle;
            } else {
                begin = middle +1;
            }
        }
        if(nums[begin] >= target){
            return begin;
        } else{
            return  begin +1;
        }
    }
};
// @lc code=end

