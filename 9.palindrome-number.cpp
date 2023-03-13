/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 ){
            return false;
        }
        if(x == 0){
            return true;
        }
        vector<int> numSplit;
        int a = x;
        while(a != 0){
            numSplit.push_back(a%10);
            a = a/10;
        }
        int begin = 0;
        int end = numSplit.size()-1;
        int res = true;
        while(begin < end){
            if(numSplit[begin] != numSplit[end]){
                res = false;
                break;
            }
            begin++;
            end--;
        }
        return res;
    }
};
// @lc code=end

