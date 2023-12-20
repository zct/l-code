/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Number of Provinces
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        parent.resize(isConnected.size());
        for(int i = 0; i < isConnected.size(); i++){
            parent[i] = i;
        }
        for(int i = 0; i < isConnected.size(); i++){
            for(int j = 0; j < isConnected[0].size(); j++){
                if(isConnected[i][j] == 1 && i != j){
                    unionA(i, j);
                }
            }
        }
        int res = 0;
        for(int i = 0; i < isConnected.size(); i++) {
            if(parent[i] == i){
                res++;
            }
        }
        return res;
    }

    void unionA(int p, int q){
        int p_parent = find(p);
        int q_parent = find(q);
        parent[q_parent] = p_parent;
    }
    
    int find(int p){
        while(parent[p] != p){
            p = parent[p];
        }
        return p;
    }

private:
    vector<int> parent;
};
// @lc code=end

