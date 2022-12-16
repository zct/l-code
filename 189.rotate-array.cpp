/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        reverse(nums, 0, nums.size()-k-1);
        reverse(nums, nums.size()-k, nums.size()-1);
        reverse(nums, 0, nums.size()-1);
    }

    void reverse(vector<int>& nums, int begin, int end){
        if(begin < 0 || begin >= end || end >=nums.size()){
            return;
        }
        while(begin < end){
            int temp = nums[begin];
            nums[begin++] = nums[end];
            nums[end--] = temp;
        }
        return;
    }
};
// @lc code=end

