/*
 * @lc app=leetcode id=350 lang=cpp
 *
 * [350] Intersection of Two Arrays II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> countMap;
        for (int i = 0; i < nums1.size(); i++)
        {
            countMap[nums1[i]]++;
        }
        vector<int> res;
        for (int i = 0; i < nums2.size(); i++)
        {
            if (countMap[nums2[i]] != 0)
            {
                res.push_back(nums2[i]);
                countMap[nums2[i]]--;
            }
        }
        return res;
    }
};
// @lc code=end

