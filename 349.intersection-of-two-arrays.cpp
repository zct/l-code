/*
 * @lc app=leetcode id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    //解法1： 对于nums1中的每个数字，判断nums2中是否存在
    //解法2： 用一个map
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> countMap;
        for(int i = 0; i < nums1.size(); i++){
            countMap[nums1[i]]++;
        }
        vector<int> res;
        for(int i = 0; i < nums2.size(); i++){
            if(countMap[nums2[i]] != 0){
                res.push_back(nums2[i]);
                countMap[nums2[i]] = 0;
            }
        }
        return res;
    }
};
// @lc code=end

