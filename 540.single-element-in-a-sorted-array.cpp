/*
 * @lc app=leetcode id=540 lang=cpp
 *
 * [540] Single Element in a Sorted Array
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int begin = 0; 
        int end = nums.size()-1;
        int res =  0;
        while(begin <= end){
            int middle = (begin+end)/2;
            cout << begin << end << middle << endl;
            if(middle == 0 || middle == nums.size()){
                res = middle;
                break;
            }
            if(nums[middle-1] == nums[middle]){
                if((middle-begin+1) %2 == 0){
                    begin = middle+1;
                } else {
                    end = middle;
                }
            } else if(nums[middle+1] == nums[middle]){
                if((middle-begin+2) %2 == 0){
                    begin = middle+2;
                } else {
                    end = middle-1;
                }

            } else {
                res = middle;
                break;
            }
        }
        return nums[res];
    }
};
// @lc code=end

