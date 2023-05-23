/*
 * @lc app=leetcode id=229 lang=cpp
 *
 * [229] Majority Element II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
//用两个count
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        vector<int> res;
        int count1 = 0;
        int count2 = 0;
        int num1 = 0;
        int num2 = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == num1){
                count1++;
            } else if(nums[i] == num2){
                count2++;
            } else if(count1 == 0){
                num1 = nums[i];
                count1++;
            } else if(count2 == 0){
                num2 = nums[i];
                count2++;
                continue;
            }else {
                count1--;
                count2--;
            }
        }
        count1 = 0;
        count2 = 0;
        cout << num1 << num2 << endl;
        for(auto& num:nums){
            if(num == num1){
                count1++;
            } else if(num == num2){
                count2++;
            }
        }
        if(count1 > nums.size()/3){
            res.push_back(num1);
        }
        if(count2 > nums.size()/3){
            res.push_back(num2);
        }
        return res;
        
       
       
    }
};
// @lc code=end

