/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int reverse(long x) {
        if(x == 0){
            return 0;
        }
        vector<int> numSplit;
        int isPostive = 1;
        if(x < 0)
            isPostive = -1;
        int a = x;
        while(a != 0){
            numSplit.push_back(a %10);
            a = a / 10;
        }
        bool beginZero = numSplit[0] == 0;
        long res = 0;
        for(int i = 0; i < numSplit.size(); i++){
            if(numSplit[i] == 0 && beginZero){
                continue;
            } else {
                beginZero = false;
                res = res*10 + numSplit[i];
                if(res > __INT32_MAX__ || res < INT_MIN){
                    return 0;
                }
            }
        } 
        return res  ;
    }
};
// @lc code=end

