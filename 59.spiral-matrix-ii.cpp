/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n ,vector<int>(n , 0));
        vector<vector<int>> spiralIndex;
        spiralIndex.push_back(vector<int>{0, 1});
        spiralIndex.push_back(vector<int>{1, 0});
        spiralIndex.push_back(vector<int>{0, -1});
        spiralIndex.push_back(vector<int>{-1, 0 });
        int totalNumer = n * n;
        int index = 1;
        int i = 0;
        int j = 0;
        int k = 0;
        while(index <= totalNumer){
            if(i >= 0 && i < n && j >=0 && j < n && res[i][j] == 0){
                res[i][j] = index++;
                i = i + spiralIndex[k%4][0];
                j = j +spiralIndex[k%4][1];
            } else {
                i = i - spiralIndex[k%4][0];
                j = j -spiralIndex[k%4][1];
                k++;
                i = i + spiralIndex[k%4][0];
                j = j +spiralIndex[k%4][1];
            }
        }
        return res;
    }
};
// @lc code=end

