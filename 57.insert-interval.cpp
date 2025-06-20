/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int cur = 0;
        int n = intervals.size();
        while(cur < n && intervals[cur][1] < newInterval[0]){
            res.push_back(intervals[cur++]);
        }
        while(cur < n &&  intervals[cur][0] <= newInterval[1]){
            newInterval[0] = min(intervals[cur][0], newInterval[0]);
            newInterval[1] = max(intervals[cur][1], newInterval[1]);
            cur++;
        }
        res.push_back(newInterval);
        while(cur < n){
            res.push_back(intervals[cur]); cur++;
        }
        return res;
    }
};
// @lc code=end

