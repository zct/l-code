/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size()){
            return "";
        }
        for(int i = 0; i < t.size(); i++){
            setTarget.insert(t[i]);
            cout << t[i] << endl;
        }
        int begin = 0;
        int end = 0;
        //滑动窗口
        string res ;
        int minSize = s.size();
        while(begin < s.size()){
            while(end < s.size() && AddMap(s[end++]) < t.size()){
            }
            if((end - begin) <= minSize && mapCount.size() == t.size()){
                res = s.substr(begin, end-begin);
                minSize = end-begin+1;
            }

            while(EraseMap(s[begin++]) == t.size()){
            }
            if((end - begin + 2) < minSize){
                res = s.substr(begin-1, end-begin+2);
                minSize = end-begin+2;
            }
            if (end == s.size()){
                break;
            }
        }
        return res;
    }

    int AddMap(char c){
    if(setTarget.count(c) != 0){
        if(mapCount.count(c) == 0){
            mapCount[c] = 1;
        } else {
            mapCount[c]++;
        }
        }
        return mapCount.size();
    }
    
    int EraseMap(char c){
        if(setTarget.count(c) != 0){
            if(mapCount[c] == 1){
                mapCount.erase(c);
            } else {
                mapCount[c]--;
            }
        }
        return mapCount.size();
    }
    
    private:
    map<char, int> mapCount;
    set<char> setTarget;
};
// @lc code=end

