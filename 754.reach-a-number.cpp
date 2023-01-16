/*
 * @lc app=leetcode id=754 lang=cpp
 *
 * [754] Reach a Number
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

struct ReachNode {
    int step;
    int curNum;
};

class Solution {
public:
    int reachNumber(int target) {
        queue<ReachNode*> bfsQueue;
        ReachNode* initNode = new(ReachNode);
        int step = 0;
        initNode->step = step;
        initNode->curNum = 0;
        bfsQueue.push(initNode);
        while(!bfsQueue.empty()){
            ReachNode* tempNode = bfsQueue.front();
            bfsQueue.pop();
            step = tempNode->step;
            step++;
            int num = tempNode->curNum;
            
            if(num+step== target){
                break;
            } else if(num - step == target){
                break;
            } else {
                ReachNode* firstNode = new(ReachNode);
                ReachNode* secondNode = new(ReachNode);
                firstNode->step = step;
                firstNode->curNum = num +step;
                secondNode->step = step;
                secondNode->curNum = num -step;
                bfsQueue.push(firstNode);
                bfsQueue.push(secondNode);
            }
        }
        return step;
    }
};
// @lc code=end

