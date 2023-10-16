/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

// @lc code=start
#include <bits/stdc++.h>

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        this->nums= nums;
        sort(this->nums.begin(), this->nums.end());
        vector<int> used;
        used.resize(this->nums.size());
        //如何剪枝
        vector<int> permute;
        backtrack(0, permute, used);
        return this->res;
        
    }
    void backtrack(int idx, vector<int>& permute, vector<int>& used){
        if(idx == nums.size()){
            this->res.push_back(permute);
        }
        for(int i = 0; i < nums.size(); i++){
        if(used[i]  || (i > 0 &&  nums[i] == nums[i-1] && used[i-1] == false)){
            continue;
        }
        permute.push_back(nums[i]);
        used[i] = true;
        backtrack(idx+1, permute, used);
        permute.pop_back();
        used[i] = false;
        
        }
    }
private:
    vector<int> nums;
    vector<vector<int>> res;
};
// @lc code=end

