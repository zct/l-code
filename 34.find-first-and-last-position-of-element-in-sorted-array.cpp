/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
       vector<int> res{-1, -1};
       int begin = 0;
       int end = nums.size()-1;
       while(begin <= end){
           int middle = (begin+end)/2;
           if(nums[middle] == target){
               res[0] = middle;
               end = middle -1;
           } else if(nums[middle] > target){
               end = middle -1;
           } else {
               begin = middle + 1;
           }
       }
       begin = 0;
       end = nums.size() -1;
       while(begin <= end){
           int middle = (begin+end)/2;
           if(nums[middle] == target){
               res[1] = middle;
               begin = middle +1;
           } else if(nums[middle] > target){
               end = middle -1;
           } else {
               begin = middle + 1;
           }
       }
       return res;
    }
};
// @lc code=end

