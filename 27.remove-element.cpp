/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int valCount = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == val){
                valCount++;
            } else {
                nums[i-valCount] = nums[i];
            }
        }
        return nums.size() - valCount;
    }
};
// @lc code=end

