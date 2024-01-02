/*
 * @lc app=leetcode id=371 lang=cpp
 *
 * [371] Sum of Two Integers
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int getSum(int a, int b) {
        while(b != 0){
            int carry = (a & b) << 1;
            a = a ^ b;
            b = carry;
        }
        return a;
    }
};
// @lc code=end

