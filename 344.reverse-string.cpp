/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void reverseString(vector<char>& s) {
        int begin = 0;
        int end = s.size()-1;
        while(begin <= end){
            swap(s[begin++], s[end--]);
        }
    }
};
// @lc code=end

