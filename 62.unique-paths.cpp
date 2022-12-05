/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        this->row = m;
        this->col = n;
        this->count = 0;
        vector< vector<int> > f(m ,vector<int>(n, 0));
        for(int i = 0; i < m; i++){
            f[i][0] = 1;
        }
        for(int j = 0; j < n; j++) {
            f[0][j] = 1;
        }
        for(int i = 1 ; i < m; i++){
            for(int j = 1; j < n; j++) {
                f[i][j] = f[i-1][j] + f[i][j-1];
            }
        }
        return f[m-1][n-1];
    }


    private:
    int row;
    int col;
    int count ;
};
// @lc code=end

