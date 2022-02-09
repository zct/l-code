/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start
#include <string>
#include <iostream>

using namespace std;



bool isdigit(char c) {
    if( c  >= '0' && c <= '9')
        return true;
    return false;
}

class Solution {
public:
    int myAtoi(string s) {

        int res = 0;
        bool negative = false;
        for(int i = 0 ; i< s.size(); i++){
            if(s[i] == ' ')
                continue;

            if(s[i] == '-'){
                negative = true;
                continue;
            }

            if(!isdigit(s[i])){
                break;
            }
            int num = s[i] - '0';
            
            if(res > INT_MAX / 10 || (res == INT_MAX/10 && 
                num > INT_MAX % 10) )
            {
                if(negative)
                    return INT_MIN;
                else    
                    return INT_MAX;
            }
            res = res * 10 + num;
        }
        if(negative){
            res = res * -1;
        }
        return res;
    }

    
};

// @lc code=end

