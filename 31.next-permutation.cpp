/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    //从后向前扫描，从降序序列中找一个比较小的元素与这个降序序列
    //前面的一个数字进行交换
    void nextPermutation(vector<int>& nums) {
        bool found = false;
        int index1 = 0;
        for(int i = nums.size() -2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                found = true;
                index1 = i;
                break;
            }
        }
        if(!found){
            sort(nums.begin(), nums.end());
            return;
        }
        int index2 = index1+1;
        int minV =  nums[index2];
        for(int i = index2 ; i < nums.size(); i++){
            if(nums[i] > nums[index1] && nums[i] < minV){
                index2 = i;
                minV = nums[i];
            }
        }
        swap(nums[index1], nums[index2]);
        sort(nums.begin() + index1+1, nums.end());
    }
private:
};
// @lc code=end

