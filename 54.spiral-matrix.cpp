/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rowBegin = 0;
        int rowEnd = matrix.size()-1;
        int colBegin = 0;
        int colEnd = matrix[0].size()-1;
        vector<int> res;
        vector<pair<int, int>> direction;
        direction.push_back(pair<int,int>(0,1));
        direction.push_back(pair<int, int>(1, 0));
        direction.push_back(pair<int,int>(0, -1));
        direction.push_back(pair<int,int>(-1, 0));
        int i = 0; int j = 0;
        int index = 0;
        while(i>=rowBegin && i <= rowEnd && j >= colBegin && j <= colEnd){
            res.push_back(matrix[i][j]);
            if(index % 4 == 0 && j == colEnd){
                rowBegin++;
                index++;
            }
            if(index %4 == 1 && i == rowEnd){
                index++;
                colEnd--;
            }
            if( index % 4 == 2 && j == colBegin){
                index++;
                rowEnd--;
            }
            if(index % 4 == 3 && i == rowBegin){
                index++;
                colBegin++;
            }
            i += direction[index % direction.size()].first;
            j += direction[index % direction.size()].second;
        }
        return res;
    }
};
// @lc code=end

