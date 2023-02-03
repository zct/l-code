/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> numSet(nums.begin(), nums.end());
        //左边存在--
        //右边存在++
        int res = 0;
        for(auto num:nums){
            if(numSet.count(num-1) != 0){
                continue;
            } else {
                int tempRes = 1;
                while(numSet.count(++num) != 0) {
                    tempRes++;
                }
                res = max(res, tempRes);
            }
        }
        return res;
    }
};
// @lc code=end

