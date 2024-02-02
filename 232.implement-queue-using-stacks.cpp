/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

//使用双队列
class MyQueue {
public:
    MyQueue() {
    }
    
    void push(int x) {
        inStack.push(x);
    }
    
    int pop() {
        int ret = this->peek();
        outStack.pop();
        return ret;
    }
    
    int peek() {
        if(outStack.size() == 0){
            if(inStack.size() == 0){
                return 0;
            } else {
                while(inStack.size() != 0){
                    outStack.push(inStack.top());
                    inStack.pop();
                }
            }
        }
        int ret = outStack.top();
        return ret;
    }
    
    bool empty() {
        return inStack.size() == 0 && outStack.size() == 0;
    }
private:
    stack<int> inStack;
    stack<int> outStack;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

