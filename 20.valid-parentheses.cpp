/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> sBrackets;
        map<char, char> mapBrackets;
        mapBrackets['('] = ')';
        mapBrackets['['] = ']';
        mapBrackets['{'] = '}';
        for(int i = 0; i < s.size(); i++){
            //左括号，入栈
            if(mapBrackets.count(s[i]) != 0){
                sBrackets.push(s[i]);
            } else {
                if(sBrackets.size() == 0){
                    return false;
                }
                char topChar = sBrackets.top();
                if(mapBrackets[topChar] != s[i]){
                    return false;
                }
                sBrackets.pop();
            }
        }
        return sBrackets.size() != 0 ? false:true;
    }
};
// @lc code=end

