/*
 * @lc app=leetcode id=684 lang=cpp
 *
 * [684] Redundant Connection
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //看到一个节点有两个root，可以删除
    //并查集
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = 0;
        for(int i = 0; i < edges.size(); i++){
            int temp = max(edges[i][0], edges[i][1]);
            n = max(temp, n);
        }
        parent.resize(n+1, 0);
        for(int i = 0; i < n+1; i++){
            parent[i] = i;
        }
        int res = 0;
        for(int i = 0; i < edges.size(); i++){
            int p = edges[i][0];
            int q = edges[i][1];
            if(find(p) == find(q)){
                res = i;
                break;
            } else {
                unionA(p, q);
            }
        }
        return edges[res];
    }
    
    int find(int p){
        while(parent[p] != p){
            p = parent[p];
        }
        return p;
    }
    void unionA(int p , int q){
        int p_parent = find(p);
        int q_parent = find(q);
        parent[q_parent] = p_parent;
    }
private:
    vector<int> parent;
};
// @lc code=end

