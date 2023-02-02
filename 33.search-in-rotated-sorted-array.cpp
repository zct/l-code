/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int begin = 0;
        int end = nums.size() -1;
        while(begin < end){
            int middle = (begin + end)/2;
            if(nums[middle] == target){
                return middle;
            }
            if(nums[begin] <= nums[middle]){
                if(target >= nums[begin] && target <= nums[middle]){
                    end = middle-1;
                } else {
                    begin = middle+1;
                }
            } else if(nums[begin] > nums[middle]){
                if(target >= nums[middle] && target <= nums[end]){
                    begin = middle+1;
                } else {
                    end = middle-1;
                }
            }
        }
        if(nums[begin] == target){
            return begin;
        }
        return -1;
    }
};
// @lc code=end

