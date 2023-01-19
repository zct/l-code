/*
 * @lc app=leetcode id=223 lang=cpp
 *
 * [223] Rectangle Area
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int rowOverlap = 0;
        int colOverlap = 0;
        if(!(ax1 >= bx2 || bx1 >= ax2)){
            rowOverlap  = min(bx2, ax2) - max(bx1, ax1);
        }
        if(!(ay1 >= by2 || by1 >= ay2)){
            colOverlap = min(by2, ay2) - max(by1, ay1);
        }
        int overlapArea = rowOverlap * colOverlap;
        int aArea = (ax2-ax1) * (ay2- ay1);
        int bArea = (bx2-bx1) * (by2 - by1);
        return aArea + bArea - overlapArea;
    }
};
// @lc code=end

