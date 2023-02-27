/*
 * @lc app=leetcode id=392 lang=cpp
 *
 * [392] Is Subsequence
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        map<char, vector<int> > mapIndex;
        for(int i = 0; i < t.size(); i++){
            mapIndex[t[i]].push_back(i);
        }
        int minIndex =-1;
        bool res = true;
        for(int i = 0; i < s.size(); i++){
            if(mapIndex.count(s[i]) == 0){
                res = false;
                break;
            } else {
                if(mapIndex[s[i]].back() <= minIndex){
                    res = false;
                    break;
                } else {
                    for(int j = 0; j < mapIndex[s[i]].size(); j++){
                        if(mapIndex[s[i]][j] > minIndex){
                            minIndex = mapIndex[s[i]][j];
                            break;
                        }
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end

