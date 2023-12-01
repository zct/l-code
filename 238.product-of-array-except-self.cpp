/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        map<int, int> zeroCount;
        int allProduct = 1;
        for(int i = 0 ; i < nums.size(); i++){
            allProduct  *= nums[i];
            if(nums[i] == 0){
                zeroCount[i] = 1;
            }
        }
        vector<int> res;
        for(int i = 0; i < nums.size(); i++){
        if(zeroCount.size() == 0){
            res.push_back(allProduct/nums[i]);
        } else if(zeroCount.size() == 1){
            if(zeroCount.count(i) != 0){
                int tProduct = 1;
                for(int j = 0;j < i; j++){
                    tProduct *= nums[j];
                }
                for(int j = i+1; j < nums.size(); j++){
                    tProduct *= nums[j];
                }
                res.push_back(tProduct);
            } else {
                res.push_back(0);
            }
        } else {
            res.push_back(0);
        }
        }
        return res;
        
    }
};
// @lc code=end

