/*
 * @lc app=leetcode id=605 lang=cpp
 *
 * [605] Can Place Flowers
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n == 0){
            return true;
        }
        //贪心算法；
        int res = false;
        int len = flowerbed.size();
        int i = 0;
        while(i < len){
            if(flowerbed[i] == 1){
                i += 2;
            } else {
                if( i == (len -1)){
                    n--;
                    i++;
                } else {
                    if(flowerbed[i+1] == 0){
                        flowerbed[i] = 1;
                        n--;
                    } else {
                        i++;
                    }
                }
            }
            if(n == 0){
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

