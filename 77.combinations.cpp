/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //组合
    vector<vector<int>> combine(int n, int k) {
        this->limit = k;
        this->num = n;
        vector<int> comb;
        dfs(comb, 0);
        return res;
    }
    //
    void dfs(vector<int>& comb, int index){
        if(comb.size() == limit){
            res.push_back(comb);
        }
        for(int i = index; i < num; i++){
            comb.push_back(i+1);
            dfs(comb, i+1);
            comb.pop_back();
        }
    }
    private:
        int limit;
        int num;
        vector<vector<int> > res;
};
// @lc code=end

