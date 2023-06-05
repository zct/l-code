/*
 * @lc app=leetcode id=409 lang=cpp
 *
 * [409] Longest Palindrome
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> countMap;
        for(int i = 0; i < s.size(); i++){
            if(countMap.count(s[i]) != 0){
                countMap[s[i]]++;
            } else{
                countMap[s[i]] = 1;
            }
        }
        int len = 0;
        bool allT = true;
        for(auto iter = countMap.begin(); iter != countMap.end(); iter++){
            if(iter->second % 2 == 0){
                len += iter->second;
            } else {
                allT = false;
                len += (iter->second/2)*2;
            }
        }
        if(!allT){
            len+=1;
        }
        return len;
        
    }
};
// @lc code=end

