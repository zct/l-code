/*
 * @lc app=leetcode id=451 lang=cpp
 *
 * [451] Sort Characters By Frequency
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

struct cmp{
    bool operator()(const pair<char,int>& a, const pair<char,int>& b){
        return a.second < b.second;
    }
};

class Solution {
public:
    string frequencySort(string s) {
        map<char, int> wordCount;
        for(auto c : s){
            wordCount[c]++;
        }
        priority_queue<pair<char, int>, vector<pair<char,int>>, cmp> pq;
        for(auto iter = wordCount.begin(); iter != wordCount.end(); iter++){
            pq.push(pair<char,int>(iter->first, iter->second));
        }
        string res;
        while(!pq.empty()){
            auto pairV = pq.top();

            res = res.append(pairV.second, pairV.first);
            pq.pop();
        }
        return res;
    }
};
// @lc code=end

