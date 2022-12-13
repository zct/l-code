/*
 * @lc app=leetcode id=395 lang=cpp
 *
 * [395] Longest Substring with At Least K Repeating Characters
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        if(s.size() < k) 
            return 0;
        map<char, int> mapCount;
        for(int i = 0; i < s.size(); i++){
            if(mapCount.find(s[i]) != mapCount.end()){
                mapCount[s[i]]++;
            } else {
                mapCount[s[i]] = 1;
            }
        }
        vector<int> vecPos;
        for(int i = 0 ; i < s.size(); i++) {
            if(mapCount[s[i]] < k) {
                vecPos.push_back(i);
            }
        }
        if(vecPos.size() == 0){
            return s.size();
        }
        int prev = -1;
        int res = 0;
        for(int i = 0; i < vecPos.size(); i++) {
            string subStr;
            if(vecPos[i] == 0){
                prev = 0;
                continue;
            } else if(vecPos[i] == int(s.size() -1)){
                subStr = s.substr(0, s.size()-1).substr(prev+1);
            }else {
                subStr = s.substr(prev+1, vecPos[i]-prev-1);
                prev = vecPos[i];
            }    

            
             if (subStr.size()  < k){
                continue;
            }
            res = max(res, this->longestSubstring(subStr, k));
        }
        if(prev < s.size() -1){
            res = max(res, this->longestSubstring(s.substr(prev+1), k));
        }
        return res;
    }
};
// @lc code=end

