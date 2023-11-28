/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0){
            return "";
        }
        int len = 0;
        for(int i = 0; i < strs[0].size(); i ++){
        for(int j = 1 ; j < strs.size(); j++){
            if(strs[j][i] != strs[0][i]){
                return strs[0].substr(0, len);
            }
        }
        len++;
        }
        return strs[0].substr(0,len);
    }
};
// @lc code=end

