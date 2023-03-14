/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map<char, int> charCount1;
        vector<vector<map<char,int>>> charCount(3, vector<map<char,int>>(9, charCount1));
        for(int i = 0 ; i < 9; i++){
            for(int j = 0 ; j < 9; j++){
                if(board[i][j] != '.'){
                    if((charCount[0][i][board[i][j]])++ >= 1){
                        return false;
                    }
                    if((charCount[1][j][board[i][j]])++ >= 1){
                        return false;
                    }
                    if((charCount[2][(i/3)*3 + j/3][board[i][j]])++ >= 1){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
// @lc code=end

