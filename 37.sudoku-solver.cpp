/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }

    bool solve(vector<vector<char>>& board, int i, int j){
        if(i == board.size() ){
            return true;
        }
        if(j == board.size()){
            return solve(board, i+1, 0);
        }
        if(board[i][j] != '.'){
            return solve(board, i, j+1);
        }
        for(int k = 0; k < 9; k++){
            char posChar = '1' + k;
            if(isValid(board, i, j, posChar)){
                board[i][j] = posChar;
                if(!solve(board, i, j+1)){
                   board[i][j] = '.';
                } else {
                    return true;
                }
            }
        }
        return false;
    }

    bool isValid(vector<vector<char>>& board, int i, int j, char c){
        for(int k = 0; k < 9; k++){
            if(board[i][k] == c && k != j) return false;
            if(board[k][j] == c && k != i) return false;
            int row = (i/3)*3 + k/3;
            int col = (j/3)*3 + k%3;
            if(board[row][col] == c &&  row != i && col != j) return false; 
        }
        return true;
    }
};
// @lc code=end

