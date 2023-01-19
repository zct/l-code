/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int begin = 1;
        int end = nums.size() ;
        while(begin < end){
            int middle = (begin +end) /2;
            cout << middle << endl;
            if(begin == end -1){
                int beginIndex = 0;
                int endIndex = 0;
                for(auto num:nums){
                    if(num == begin){
                        beginIndex++;
                    }
                    if(num == end){
                        endIndex++;
                    }
                }
                if(beginIndex > 1){
                    return begin;
                } else {
                    return end;
                }
            }
            int count = 0;
            for(auto num : nums ){
                if(num < middle){
                    count++;
                }
            }
            if(count >= middle){
                end = middle -1  ;
            } else {
                begin = middle  ;
            }
        }
        return begin;
    }
};
// @lc code=end

