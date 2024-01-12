/*
 * @lc app=leetcode id=1109 lang=cpp
 *
 * [1109] Corporate Flight Bookings
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> res(n+1, 0);
        for(int i = 0; i < bookings.size(); i++){
            res[bookings[i][0]-1] += bookings[i][2];
            res[bookings[i][1]] +=  (-1 * bookings[i][2]);
        }
        res.pop_back();
        for(int i = 1; i < n; i++){
            res[i] += res[i-1];
        }
        return res;
    }
};
// @lc code=end

