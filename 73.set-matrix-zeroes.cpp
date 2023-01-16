/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.size() == 0){
            return;
        }
        int rowSize = matrix.size();
        int colSize = matrix[0].size();
        bool rowTag = false;
        bool colTag = false;
        for(int i = 0; i < rowSize; i++){
            if(matrix[i][0] == 0){
                rowTag = true;
                break;
            }
        }
        for(int j = 0; j< colSize; j++){
            if(matrix[0][j] == 0){
                colTag = true;
                break;
            }
        }
        if(rowTag && colTag){
            matrix[0][0] = 0;
        }
        for(int i = 1; i <rowSize; i++){
            for(int j = 1; j < colSize; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i = 1 ; i < rowSize; i++){
            if(matrix[i][0] == 0){
                for(int j = 0; j < colSize; j++){
                    matrix[i][j] = 0;
                }
            }
        }
        for(int j = 1; j < colSize; j++){
            if(matrix[0][j] == 0){
                for(int i = 0; i < rowSize; i++){
                    matrix[i][j] = 0;
                }
            }
        }
        if(rowTag){
            for(int i = 0; i < rowSize;i++){
                matrix[i][0]  = 0;
            }
        }
        if(colTag) {
            for(int j = 0; j< colSize;j++){
                matrix[0][j] = 0;
            }
        }
    }
};
// @lc code=end

