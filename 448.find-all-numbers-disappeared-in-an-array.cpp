/*
 * @lc app=leetcode id=448 lang=cpp
 *
 * [448] Find All Numbers Disappeared in an Array
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int index = 0;
        vector<int> res;
        while(index< nums.size()){
            if(nums[index] != index+1){
                if(nums[index] == nums[nums[index]-1]){
                    index++;
                } else {
                swap(nums[index], nums[nums[index]-1]);
                }
            } else {
                index++;
            }
        }
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != i+1){
                res.push_back(i+1);
            }
        }
        return res;
    }
};
// @lc code=end

