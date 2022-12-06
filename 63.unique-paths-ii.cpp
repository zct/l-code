/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int> > f(m, vector<int>(n, 0));
        int obstacle = 1;
        for(int i = 0; i < m; i++){
            if(obstacleGrid[i][0] == 1){
                obstacle = 0;
            }
            f[i][0] = obstacle;
        }
        obstacle = 1;
        for(int i = 0; i < n; i++){
            if(obstacleGrid[0][i] == 1){
                obstacle = 0;
            }
            f[0][i] = obstacle;
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(obstacleGrid[i][j] == 1) {
                    f[i][j]  = 0;
                } else {
                    f[i][j] = f[i-1][j] + f[i][j-1];
                }
            }
        }
        return f[m-1][n-1];
    }
};
// @lc code=end

