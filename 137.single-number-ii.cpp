/*
 * @lc app=leetcode id=137 lang=cpp
 *
 * [137] Single Number II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //统计每一位1出现的次数
    
    int singleNumber(vector<int>& nums) {
        vector<int> bitCount(32, 0);
        for(auto num : nums){
            for(int i = 0; i < 32; i++){
                bitCount[i] += (num >> i) & 1;
            }
        }
        int res  = 0;
        for(auto i = 0; i < 32; i++){
            if(bitCount[i] % 3 != 0){
                res += 1 << i;
            }
        }
        return res;
    }
};
// @lc code=end

