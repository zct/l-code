/*
 * @lc app=leetcode id=216 lang=cpp
 *
 * [216] Combination Sum III
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        this->target = n;
        this->limit = k;
        vector<int> comb;
        int sum = 0;
        dfs(1, comb, sum);
        return this->res;
    }
    void dfs(int index, vector<int>& comb, int& sum){
        if(comb.size() == limit && sum == target){
            res.push_back(comb);
            return;
        }
        if(sum > target){
            return;
        }
        for(int i = index; i <  10; i++){
            comb.push_back(i);
            sum+= i;
            dfs(i+1, comb, sum);
            comb.pop_back();
            sum-=i;
        }
    }
private:
    int target;
    int limit;
    vector<vector<int>> res;
};
// @lc code=end

