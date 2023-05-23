/*
 * @lc app=leetcode id=542 lang=cpp
 *
 * [542] 01 Matrix
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    //BFS(会超时？)
    //二次扫描法
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>> pq;
        vector<vector<int>> direction{{0,1},{1,0}, {0,-1},{-1,0}};
        int row = mat.size();
        int col = mat[0].size();
        vector<vector<int>> res(row, vector<int>(col, 0));
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(mat[i][j] == 0){
                    pq.push({i,j});
                } else {
                    res[i][j] = INT_MAX;
                }
            }
        }
        while(!pq.empty()){
            pair<int,int> node = pq.front();
            pq.pop();
            for(int i = 0; i < direction.size(); i++){
                int n_row = node.first+direction[i][0];
                int n_col = node.second+direction[i][1];
                if( n_row < 0 || n_row >= row || n_col < 0 || n_col >= col){
                    continue;
                } else {
                    if(res[n_row][n_col] <= res[node.first][node.second] + 1){
                        continue;
                    } else {
                        res[n_row][n_col] = res[node.first][node.second] +1;
                        pq.push({n_row, n_col});
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end

