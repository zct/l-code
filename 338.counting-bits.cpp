/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        for(int i = 0; i <=n; i++){
            int num = 0;
            for(int j = 0; j < 32; j++){
                if ((i >> j) % 2 != 0 ){
                    num++;
                }
            }
            res.push_back(num);
        }
        return res;
    }
};
// @lc code=end

