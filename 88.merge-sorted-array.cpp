/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    //assume nums1.len == m +n
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int num1End = m-1;
        int num2End = n-1;
        int end =  m+n-1;
        while(num1End >=0 && num2End >=0){
            if(nums1[num1End] > nums2[num2End]){
                nums1[end--] = nums1[num1End--];
            } else {
                nums1[end--] = nums2[num2End--];
            }
        }
        while(num2End >= 0){
            nums1[end--] = nums2[num2End--];
        }
    }
};
// @lc code=end

