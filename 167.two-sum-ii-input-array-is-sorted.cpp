/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input Array Is Sorted
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int index = 0;
        //二分查找？
/*        for(; index < numbers.size(); index++){
            if(numbers[index] > target)
                break;
        } */
        int begin = 0;
        int end = numbers.size()-1;
        vector<int> res;
        while(begin < end){
            if(numbers[begin]+numbers[end] > target){
                end--;
            } else if(numbers[begin] + numbers[end] < target){
                begin++;
            } else{
                res.push_back(begin+1);
                res.push_back(end+1);
                break;
            }
        }
        return res;
    }
};
// @lc code=end

