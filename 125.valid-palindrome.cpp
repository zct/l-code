/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string newS;
        for(int i = 0; i < s.size(); i++){
            if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <='z') || (s[i] >= '0' && s[i] <= '9')){
                newS.append(1, tolower(s[i]));
            }
        }
        int begin = 0;
        int end = newS.size() -1;
        bool res = true;
        while(begin < end){
            if(newS[begin++] != newS[end--]){
                res = false;
                break;
            }
        }
        return res;
    }
};
// @lc code=end

