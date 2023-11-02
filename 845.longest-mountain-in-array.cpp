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
        int i = 1;
        int ans = 0;
        while(i < arr.size()){
            int decreasing = 0;
            int increasing = 0;
            while(i < arr.size() && arr[i] > arr[i-1]){
                i++;
                increasing++;
            }
            while(i < arr.size() && arr[i] < arr[i-1]){
                i++;
                decreasing++;
            }
            if(increasing > 0 && decreasing > 0){
                ans = max(increasing+decreasing+1, ans);
            }
            while(i < arr.size() && arr[i] == arr[i-1])
                i++;
        }
        return ans;
    }
};
// @lc code=end

