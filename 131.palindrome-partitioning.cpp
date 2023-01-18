/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> vecStr;
        backtracking(s, 0, vecStr);
        return this->res;
    }
    
    void backtracking(string s, int begin, vector<string>& vecStr){
        if(begin == s.size()){
            vector<string> a = vecStr;
            res.push_back(a);
        }
        for(int end = begin; end< s.size(); end++){
            if(isPalindrome(s, begin ,end)){
                vecStr.push_back(s.substr(begin, end-begin+1));
                backtracking(s, end+1, vecStr);
                vecStr.pop_back();
            }
        }
    }

    bool isPalindrome(string s, int begin, int end){
        while(begin < end){
            if(s[begin++] != s[end--]){
                return false;
            }
        }
        return true;
    }
private:
    vector<vector<string>> res;
};
// @lc code=end

