/*
 * @lc app=leetcode id=680 lang=cpp
 *
 * [680] Valid Palindrome II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        bool res = true;
        int begin = 0;
        int end = s.size()-1;
        while(begin < end){
            if(s[begin] != s[end]){
                res = false;
                break;
            }else {
                begin++;
                end--;
            }
        }
        if(res == true){
            return res;
        }
        res = true;
        int newBegin = begin + 1;
        int newEnd = end;
        while(newBegin < newEnd){
            if(s[newBegin++] != s[newEnd--]){
                res = false;
                break;
            }
        }
        if(res == true){
            return res;
        }
        res = true;
         newBegin = begin ;
         newEnd = end-1;
        while(newBegin < newEnd){
            if(s[newBegin++] != s[newEnd--]){
                res = false;
                break;
            }
        }
        return res;
    }
};
// @lc code=end

