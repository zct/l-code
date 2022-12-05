/*
 * @lc app=leetcode id=134 lang=cpp
 *
 * [134] Gas Station
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if(gas.size() == 0) {
            return -1;
        }
        int res = -1;
        int nextIndex = 0;
        for(int i = 0; i < gas.size(); i++){
            if(gas[i] == 0){
                continue;
            }
            if(computeGas(gas, cost ,i, nextIndex)) {
                res = i;
                break;
            } else {
                if(nextIndex > i){
                    i = nextIndex;
                }
            }
        }
        return res;
    }

    bool computeGas(const vector<int>& gas, const vector<int>& cost, int startIndex, int& nextIndex){
        int sum = 0;
        for(int i = 0; i < gas.size(); i++){
            int gasIndex = (startIndex + i) % gas.size();
            // int costIndex = (startIndex+i+1) % gas.size();
            sum = sum + gas[gasIndex] - cost[gasIndex];
            if(sum < 0) {
                nextIndex = gasIndex ;
                return false;
            }
        }
        return true;
    }

};
// @lc code=end

