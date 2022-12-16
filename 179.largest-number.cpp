/*
 * @lc app=leetcode id=179 lang=cpp
 *
 * [179] Largest Number
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b){
            return to_string(a) + to_string(b)  > to_string(b) + to_string(a);
        });
        string res; 
        for(int i = 0; i < nums.size(); i++){
            res.append(to_string(nums[i]));
        }
        if(res[0] == '0')
            res = res.substr(res.size()-1);
        return res;
    }
};
// @lc code=end

