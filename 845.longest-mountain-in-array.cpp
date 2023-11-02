/*
 * @lc app=leetcode id=845 lang=cpp
 *
 * [845] Longest Mountain in Array
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int isIncrease = 1;
        int res = 0;
        int ans = 1;
        for(int i = 1; i< arr.size(); i++){
             if(isIncrease == 1){
                if(arr[i] > arr[i-1]){
                    ans++;
                }  else if(arr[i] == arr[i-1]){
                    ans = 1;
                } else {
                    isIncrease = 2;
                    ans++;
                }
            } else {
                if(arr[i] >= arr[i-1]){
                    res = max(res, ans);
                    isIncrease = 1;
                } else {
                    ans++;
                }
            }
        }
        if(ans != 1 && isIncrease == 2){
            res = max(ans, res);
        }
        return res;
    }
};
// @lc code=end

