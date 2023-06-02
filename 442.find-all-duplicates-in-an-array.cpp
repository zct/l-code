/*
 * @lc app=leetcode id=442 lang=cpp
 *
 * [442] Find All Duplicates in an Array
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        set<int> res;
        int i = 0;
        while(i < nums.size()){
            if(nums[i] == i+1){
                i++;
            } else {  //不相等
                if(nums[nums[i]-1] == nums[i]){
                    res.insert(nums[i]);
                    i++;
                } else {
                    swap(nums[nums[i]-1], nums[i]);
                }
            }
        }
        vector<int> vecRes;
        for(auto& num:res){
            vecRes.push_back(num);
        }
        return vecRes;

    }
};
// @lc code=end

