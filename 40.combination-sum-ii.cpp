/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

// @lc code=start
#include <bits/stdc++.h>

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        this->nums = candidates;
        this->target = target;
        sort(nums.begin(), nums.end());
        vector<int> subarray;
        vector<int> used(nums.size(), 0);
        backtracking(0, subarray, 0, used);
        return res;
    }
    void backtracking(int idx, vector<int>& subarray, int sum, vector<int>& used){
        if(sum == target){
            res.push_back(subarray);
        }
        for(int i = idx; i < nums.size(); i++){
            if(sum+nums[i] > target){
                return;
            }
            if(i > 0 && nums[i] == nums[i-1] && !used[i-1]){
                continue;
            }
            subarray.push_back(nums[i]);
            used[i] =  1 ;
            backtracking(i+1, subarray, sum + nums[i], used);
            used[i] = 0;
            subarray.pop_back();
        }
    }
private:
    int target;
    vector<int> nums;
    vector<vector<int>> res;
};
// @lc code=end

