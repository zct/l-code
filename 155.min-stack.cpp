/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start
#include <vector>
#include <iostream>

using namespace std;

class MinStack {
public:
    MinStack() {
        vecStack.resize(0);
        minValue = 0;
    }
    
    void push(int val) {
        //update minValue
        if(vecStack.size() == 0) {
            minValue = val;
        } else {
            if(val < minValue) {
                minValue = val;
            }
        }

        vecStack.push_back(val);
    }
    
    void pop() {
        if(vecStack.size()  > 0) {
            int ret = vecStack.back();
            vecStack.pop_back();
            if (vecStack.size() ==  0 ) {
                return;
            }
            if(ret <= minValue) {
                minValue = *vecStack.begin();
                for(auto iter = vecStack.begin(); iter != vecStack.end(); iter++ ){
                    if(*iter < minValue) {
                        minValue = *iter;
                    }
                }
            }
        }
        return;
    }
    
    int top() {
        return vecStack.back();
    }
    
    int getMin() {
        return minValue;
    }
    private:
        vector<int> vecStack;
        int minValue;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

