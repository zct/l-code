/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > res;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0){
                break;
            }
            if(i> 0 && nums[i] == nums[i-1]){
                continue;
            }
            int j = i+1;
            int k = nums.size()-1;
            bool match = false;
            while(j < k){
                int sum = nums[i] + nums[j];
                sum+=nums[k];
                if(match && nums[j] == nums[j-1]){
                    j++;
                    continue;
                }
                if (sum == 0){
                    match = true;
                    res.push_back(vector<int>{nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                } else if(sum > 0){
                   k--; 
                } else {
                    j++;
                }
            }
        }
        return res;
    }
};
// @lc code=end

