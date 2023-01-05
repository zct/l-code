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
        int uniqueNum = 1;
        for(int i = 1; i <nums.size(); i++){
            if(nums[i] != nums[i-1]){
                uniqueNum++;
            }
        }
        if (uniqueNum == 1){
            nums = vector<int>(3, nums[0]);
        }
        set<vector<int> > dupSet;
        for(int i = 0; i < nums.size(); i++){
            vector<vector<int>> a = twoSum(nums, -1*nums[i], i);
            for(auto iter: a){
                dupSet.insert(iter);
            }
        }
        vector<vector<int>> res;
        for(auto iter: dupSet)
            res.push_back(iter);
        return res;
        
    }
    vector<vector<int>> twoSum(vector<int> &nums, int target, int index){
        int start = 0;
        int  end = nums.size() -1;
        vector<vector<int>> res;
        while(start < end){
            if(start == index){
                start++;
                continue;
            }
            if(end == index){
                end--;
                continue;
            }
            if(nums[start] > target)   
                break;
            if(nums[end] < target)
                break;
            if(nums[start] + nums[end] == target){
                vector<int> comb{-1*target, nums[start], nums[end]};
                sort(comb.begin(), comb.end());
                res.push_back(comb);
                start++;
                end--;
            } else if(nums[start] + nums[end] > target){
                end--;
            } else {
                start++;
            }
        }
        return res;
    }
};
// @lc code=end

