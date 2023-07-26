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
        dfs(0);
        return res;
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

