/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size();
        if(row == 0){
            return 0;
        }
        int col = matrix[0].size();
        if(col == 0)
            return 0;
        vector<vector<int>> dp(row, vector<int>(col, 0));
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(matrix[i][j] == '1'){
                    dp[i][j] = 1;
                }
            }
        }
        int maxSquare = 0;
        for(int i = 0; i < row; i++){
            if(dp[i][0] == 1){
                maxSquare = 1;
            }
        }
        for(int j = 0; j < col ;j++){
            if(dp[0][j] == 1)
                maxSquare = 1;
        }
        for(int i = 1; i < row; i++){
               for(int j = 1; j < col; j++){
                   if(matrix[i][j] == '1' && dp[i-1][j-1] != 0){
                       bool allOne = true;
                       for(int z = 1; z <= dp[i-1][j-1]; z++){
                           if(allOne == false){
                               break;
                           }
                       for(int k = i - z; k < i; k++){
                           if(matrix[k][j] != '1' ){
                               allOne = false;
                               break;
                           }
                       }
                       for(int l = j - z; l < j; l++){
                           if(matrix[i][l] != '1'){
                               allOne = false;
                               break;
                           }
                       }
                       if(allOne) {
                           dp[i][j] = z+1;
                       }
                    }
                   } else if(matrix[i][j] == '1'){
                       dp[i][j] = 1;
                   }
                    maxSquare = max(dp[i][j], maxSquare);
               }
        }
        return maxSquare * maxSquare;
    }
};
// @lc code=end

