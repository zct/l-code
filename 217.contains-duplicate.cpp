/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> mapNum;
        bool res = false;
        for(auto num : nums){
            if(mapNum.count(num) >= 1){
                return true;
            } else {
                mapNum[num] = 1;
            }
        }
        return false;
    }
};
// @lc code=end

