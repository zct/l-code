/*
 * @lc app=leetcode id=821 lang=cpp
 *
 * [821] Shortest Distance to a Character
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    //两次遍历,一次找左边的，一次找右边的
    vector<int> shortestToChar(string s, char c) {
        //
        vector<int> res(s.size(), s.size());
        for(int i = 0; i <  s.size(); i++){
            int pos = s.find(c, i);
            if(pos != -1){
                res[i] = pos - i;
            }
        }
        for(int i = 0; i < s.size(); i++ ){
            int pos = s.rfind(c, i);
            if(pos != -1) {
                res[i] = min(res[i], i - pos);
            }
        }
        return res; 
    }
};
// @lc code=end

