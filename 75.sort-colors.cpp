/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

//三路快排
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int begin = 0;
        int end = nums.size() -1;
        for(int i = 0 ; i <= end; i++) {
            if(nums[i] == 0){
                int temp = nums[begin];
                nums[begin++] =0 ;
                nums[i] = temp;
            }  else if(nums[i] == 2){
                int temp = nums[end];
                nums[end--] = 2;
                nums[i--]  = temp;
            } 
        }
    }
};
// @lc code=end

