/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int res = 0;
        int wordBegin = -1;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' '){
                if(wordBegin != -1){
                    res = i-wordBegin;
                    wordBegin = -1;
                }
                continue;
            } else {
                if(wordBegin  == -1){
                    wordBegin = i;
                }
            }
        }
        if(wordBegin != -1){
            res =  int(s.size()-wordBegin);
        }
        return res;
    }
};
// @lc code=end

