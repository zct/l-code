/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.size() <= 1){
            return 0;
        }
        int left = 0;
        int right = height.size() -1;
        int res = 0;
        while(left < right){
            if(height[left] > height[right]){
                res = max(res, height[right] * (right-left));
                right--;
            } else {
                res = max(res, height[left] * (right-left));
                left++;
            }
        }
        return res;
    }
};
// @lc code=end

