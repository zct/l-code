/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.size() ==1 ){
            if(nums[0] != 1){
                return 1;
            }
        }
        for(int i = 0; i < nums.size(); ){
            if(nums[i] <= 0 || nums[i]  == i+1 || nums[i] > nums.size() || nums[i] == nums[nums[i]-1] ){
                i++;
                continue;
            }
            int temp = nums[nums[i]-1];
            nums[nums[i]-1] = nums[i];
            nums[i] = temp;
        }
        for(int i = 0 ;i < nums.size(); i++){
            if(nums[i] != i+1){
                return i+1;
            }
        }
        return nums.size() +1;
    }
};
// @lc code=end

