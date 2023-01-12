/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    int temp = maxArea;
                    maxArea = 0;
                    dfs(grid, i, j);
                    maxArea = max(temp, maxArea);
                }
            }
        }
        return maxArea;
    }
    void dfs(vector<vector<int>>& grid, int i, int j){
        if(i < 0 || i >=grid.size()){
            return;
        }
        if(j < 0 || j >= grid[0].size()){
            return;
        }
        if(grid[i][j] == 1){
            maxArea++;
            grid[i][j] = 0;
            dfs(grid, i+1, j);
            dfs(grid, i-1, j);
            dfs(grid, i, j+1);
            dfs(grid, i, j-1);
        }
    }
private:
    int maxArea;
};
// @lc code=end

