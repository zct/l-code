/*
 * @lc app=leetcode id=191 lang=cpp
 *
 * [191] Number of 1 Bits
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int num = 0;
        for(int i =  0; i < 32; i++){
            if((n >> i) % 2 == 1){
                num++;
            }
        }
        return num;
    }
};
// @lc code=end

