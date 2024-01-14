/*
 * @lc app=leetcode id=645 lang=cpp
 *
 * [645] Set Mismatch
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 最直观的做法用个map
    // 利用位置信息, 进行替换，如果位置信息不对的就是重复的
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> res;
        int i = 0;
        while(i < nums.size()){
            if(nums[i] == i+1){
                i++;
            } else {
                if(nums[nums[i] -1] == nums[i]){
                    i++;
                    continue;
                } else {
                    swap(nums[nums[i]-1], nums[i]);
                }
            }
        }
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != i+1){
                res.push_back(nums[i]);
                res.push_back(i+1);
            }
        }
        return res;
    }
};
// @lc code=end

