/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0){
            return false;
        }
        int rowSize = matrix.size();
        int colSize = matrix[0].size();
        int rowIndex = -1;
        int begin = 0;
        int end = rowSize-1;
        while(begin <= end){
            int middle = (begin+end)/2;
            if(matrix[middle][0] >  target){
                end = middle -1;
            } else if(matrix[middle][0] < target){
                if(matrix[middle][colSize-1] >= target){
                    rowIndex = middle;
                    break;
                } else {
                    begin = middle+1;
                }
            } else {
                return true;
            }
        }
        if(rowIndex  == -1){
            return false;
        }
        begin = 0;
        end = colSize;
        while(begin <= end){
            int middle = (begin+end)/2;
            if(matrix[rowIndex][middle] > target){
                end = middle -1;
            } else if(matrix[rowIndex][middle] < target) {
                begin = middle +1;
            } else {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

