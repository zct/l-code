/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 0){
            return 0;
        }
        int num = 1;
        int before = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != before){
                nums[num] = nums[i];
                num++;
                before = nums[i];
            }
        }
        return num;
    }
};
// @lc code=end

