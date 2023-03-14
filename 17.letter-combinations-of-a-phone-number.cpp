/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> vecLetter;
        if(digits.size() == 0){
            return vecLetter;
        }
        this->digits = digits;
        intToStr['2'] = vector<string>{"a", "b", "c"};
        intToStr['3'] = vector<string>{"d", "e", "f"};
        intToStr['4'] = vector<string>{"g", "h", "i"};
        intToStr['5'] = vector<string>{"j", "k", "l"};
        intToStr['6'] = vector<string>{"m", "n", "o"};
        intToStr['7'] = vector<string>{"p", "q", "r", "s"};
        intToStr['8'] = vector<string>{"t", "u", "v"};
        intToStr['9'] = vector<string>{"w", "x", "y", "z"};
        dfs(0, "");
        for(auto s:this->res){
            vecLetter.push_back(s);
        }
        return vecLetter;
    }

    void dfs(int n, string comb){
        if(n >= this->digits.size()){
            res.insert(comb);
            return;
        }
        for(int i = 0; i < this->intToStr[this->digits[n]].size(); i++){
            string a = comb;
            dfs(n+1, a.append(intToStr[this->digits[n]][i]));
        }
    }
private:
    set<string> res;
    string digits;
    map<char, vector<string>> intToStr;
};
// @lc code=end

