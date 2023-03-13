/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> mapIndex;
        int begin = 0; 
        int end = 0;
        int res = 0;
        while(end < s.size()){
            if(mapIndex.count(s[end]) != 0){
                 res = max(res, end-begin);
                 //erase之前的记录
                 int dupPos = mapIndex[s[end]];
                for(int i = begin; i <= dupPos; i++){
                    mapIndex.erase(s[i]);
                }  
                begin = dupPos+1;
                mapIndex[s[end]] = end;
                end = end+1;
            } else {
                cout << s[end] << endl;
                res = max(res, end-begin+1);
                mapIndex[s[end]] = end;
                end++;
            }
        }
        return res;
    }
};
// @lc code=end

