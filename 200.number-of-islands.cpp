/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        num = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    num++;
                    bfs(grid, i , j);
                }
            }
        }
        return num;
    }

    void bfs(vector<vector<char>>& grid, int i, int j ){
        if(i >= grid.size() || i < 0){
            return;
        }
        if(j >= grid[0].size() || j < 0){
            return;
        }
        if(grid[i][j] == '1'){
            grid[i][j] = '2';
            bfs(grid, i+1, j);
            bfs(grid, i-1, j);
            bfs(grid, i, j+1);
            bfs(grid, i, j-1);
        }
        
    }

    private:
    int num;
};
// @lc code=end

