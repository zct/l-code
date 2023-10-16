/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        this->nums = nums;
        vector<int> subarray;
//        dfs(0);   
        backtracking(0, subarray);
        return res;
    }
    
    void backtracking(int idx, vector<int>& subarray){
        res.push_back(subarray);
        for(int i = idx; i < nums.size();i++){
            subarray.push_back(nums[i]);
            backtracking(i+1, subarray);
            subarray.pop_back();
        }
    }
    void dfs(int index){
        if(index == nums.size()){
            res.push_back(path);
            return;
        }
        dfs(index+1);
        path.push_back(nums[index]);
        dfs(index+1);
        path.pop_back();
    }
private:
vector<int> nums;
vector<vector<int>> res;
vector<int> path;
};
// @lc code=end

