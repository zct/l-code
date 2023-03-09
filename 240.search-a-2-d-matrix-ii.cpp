/*
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    /*    this->target = target;
        this->matrix = matrix;
        return subSearch(0, matrix.size()-1, 0, matrix[0].size() -1);*/
        int row = 0;
        int col = matrix[0].size() -1;
        bool res = false;
        while(col >= 0 && row < matrix.size()){
            if(col == 0 && row == matrix.size()-1){
                res = matrix[row][col] == target;
            }
            if(matrix[row][col] > target){
                col--;
            } else if(matrix[row][col] < target){
                row++;
            } else {
                res = true;
                break;
            }
        }
        return res ;
    }
    
    bool subSearch(int rowBegin, int rowEnd, int colBegin, int colEnd){
        if(rowBegin > rowEnd){
            return false;
        }
        if(colBegin > colEnd){
            return false;
        }
        if(rowBegin == rowEnd && colBegin == colEnd){
            return this->matrix[rowBegin][colBegin] == this->target;
        }
        bool res = false;
        int rowMiddle = (rowBegin + rowEnd)/2;
        int colMiddle = (colBegin + colEnd)/2;
        if(this->matrix[rowMiddle][colMiddle] == this->target){
            return true;
        } else if(this->matrix[rowMiddle][colMiddle] > this->target){
            res = res || subSearch(rowBegin, rowMiddle, colBegin, colMiddle);
        } else  {
            res = res || subSearch(rowMiddle+1, rowEnd, colMiddle+1, colEnd);
        }
        res = res || subSearch(rowBegin, rowMiddle, colMiddle+1, colEnd);
        res = res || subSearch(rowMiddle+1, rowEnd, colBegin, colMiddle);
        return res;
    }
private:
    vector<vector<int>> matrix;
    int target;
};
// @lc code=end

