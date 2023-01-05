/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtracing(candidates, target);
        vector<vector<int>> a;
        for(auto vecNum: res){
            a.push_back(vecNum);
        }
        return a;
    }

    void backtracing(vector<int>& candidates, int target){
        for(auto num: candidates){
            if(num > target){
                continue;
            } else if(num == target){
                vector<int> copyVec = vecNum;
                copyVec.push_back(num);
                sort(copyVec.begin(), copyVec.end());
                res.insert(copyVec);
            } else {
                vecNum.push_back(num);
                backtracing(candidates, target-num);
                vecNum.pop_back();
            }
        }
    }
    
    private:
        vector<int> vecNum;
        set<vector<int>> res;
};
// @lc code=end

