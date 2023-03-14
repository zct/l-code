/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Find the Index of the First Occurrence in a String
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        //kmp算法
        int m = haystack.size();
        int n = needle.size();
        for(int i = 0; i <= m -n; i++){
            if(haystack.substr(i, n) == needle){
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end

