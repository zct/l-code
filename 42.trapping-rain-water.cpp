/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap2(vector<int>& height){
        int leftMax = height[0];
        int rightMax = height[height.size() -1];
        int left = 0;
        int right =  height.size() -1;
        int res = 0;
        while(left <= right){
            leftMax = max(height[left], leftMax);
            rightMax = max(height[right], rightMax);
            if(leftMax < rightMax){
                res += min(leftMax, rightMax) - height[left];
                left++;
            } else {
                res += min(leftMax, rightMax) - height[right];
                right--;
            }
        }
        return res;
    }
    int trap(vector<int>& height) {
        return trap2(height);
        int n = height.size() ;
       vector<int> leftMax(n, 0);
       vector<int> rightMax(n , 0); 
       int max = 0;
       for(int i = 0 ; i < n; i++){
           if(height[i] > max){
               max = height[i];
           } 
           leftMax[i] = max;
       }
       max = 0;
       for(int i = n-1; i>=0; i--){
           if(height[i] >  max){
               max = height[i];
           }
           rightMax[i] = max;
       }
       int res = 0;
       for(int i = 0; i < n ;i++){
           int t = min(leftMax[i], rightMax[i]) - height[i];
           if(t > 0){
               res += t;
           }
       }
       return res;
    }
};
// @lc code=end

