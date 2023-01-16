/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

    bool vecCompare(vector<int>& a , vector<int>& b){
        return a[0] < b[0];
    }
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if(intervals.size() <= 0){
            return res;
        }
        sort(intervals.begin(), intervals.end(), vecCompare);
        res.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] <= res[res.size()-1][1]){
                res[res.size()-1][1] = max(intervals[i][1], res[res.size()-1][1]);
            } else {
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};
// @lc code=end

