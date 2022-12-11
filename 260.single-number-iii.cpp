/*
 * @lc app=leetcode id=260 lang=cpp
 *
 * [260] Single Number III
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            res ^= nums[i];
        }
        int mask;
        for(int i = 31; i>=0; i--){
            mask = 1 <<i;
            if((res & mask) != 0){
                break;
            }
        }
        int a = 0;
        int b = 0;
        for(int i = 0; i < nums.size(); i++){
            if((nums[i] & mask) != 0) {
                a ^= nums[i];
            } else {
                b ^= nums[i];
            }
        }
        vector<int> vecRes;
        vecRes.push_back(a);
        vecRes.push_back(b);
        return vecRes;
    }
};
// @lc code=end

