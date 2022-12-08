/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        string res;
        stack<string> stReg;
        for(auto i = 0; i < s.size(); i++){
            if(s[i] == ']'){
                string sPattern;
                while(stReg.size() != 0){
                    string topStr = stReg.top();
                    stReg.pop();
                    if(topStr == "[") {
                        int num = 0;
                        int index = 1;
                        string s = stReg.top();
                        while(s[0] >= '0' && s[0] <= '9') {
                            num += stoi(s) * index;
                            stReg.pop();
                            if(stReg.size() == 0){
                                break;
                            }
                            s = stReg.top();
                            index *= 10;
                        }
                       string sRepeat;
                       for(int i = 0; i < num; i++){
                           sRepeat.append(sPattern);
                       }
                       stReg.push(sRepeat);
                       break;
                    } else {
                        sPattern = topStr + sPattern;
                    } 
                }
            } else {
                stReg.push(string(1, s[i]));
            }
        }
        while(stReg.size() != 0){
            res = stReg.top() + res;
            stReg.pop();
        }
        return res;
    }
};
// @lc code=end

