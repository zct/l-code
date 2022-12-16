/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> countMap;
        priority_queue<pair<int, int>> pq;
        for(auto i : nums) countMap[i]++;
        for(auto iter: countMap) pq.push({iter.second, iter.first});
        vector<int> res;
        for(int i =0; i < k ;i++){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
// @lc code=end

