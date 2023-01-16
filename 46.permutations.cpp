/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        this->nums = nums;
        vector<int> pVec;
        set<int> pIndex;
        backtracking(pVec, pIndex);
        return this->res;
    }
    
    void backtracking(vector<int>& pVec, set<int>& pIndex){
        if(pVec.size() == nums.size()){
            vector<int> tVec = pVec;
            res.push_back(tVec);
        }

        for(int i = 0; i < nums.size(); i++){
            if(pIndex.count(i) == 1){
                continue;
            }
            pVec.push_back(nums[i]);
            pIndex.insert(i);
            backtracking(pVec, pIndex);
            pVec.pop_back();
            pIndex.erase(i);
        }
    }
private:
    vector<vector<int>> res;
    vector<int> nums;
};
// @lc code=end

