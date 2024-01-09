/*
 * @lc app=leetcode id=670 lang=cpp
 *
 * [670] Maximum Swap
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    //后面的数字比前面的大, 替换总能得到最大的
    //贪心算法
    int maximumSwap(int num) {
        string strNum = to_string(num);
        int maxIdx = strNum.size() -1;
        int idx1 = -1;
        int idx2 = -1;
        for(int i = maxIdx; i >= 0; i--){
            if(strNum[i] > strNum[maxIdx]){
                maxIdx = i;
            } else if(strNum[i] < strNum[maxIdx]){
                idx1 = i;
                idx2 = maxIdx;
            }
        }
        if(idx1 >= 0){
            swap(strNum[idx1], strNum[idx2]);
            return stoi(strNum);
        } else {
            return num;
        }
    }
};
// @lc code=end

