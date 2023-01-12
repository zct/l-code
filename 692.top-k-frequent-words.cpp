/*
 * @lc app=leetcode id=692 lang=cpp
 *
 * [692] Top K Frequent Words
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
bool compareCount(const pair<string, int>& a, const pair<string, int>& b ){
    if(a.second > b.second){
        return true;
    } else if(a.second == b.second){
        string s1 = a.first + b.first;
        string s2 = b.first + a.first; 
        return s1 < s2;
    }
    return false;
}
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> wordCount;
        for(auto word:words){
            wordCount[word]++;
        }
        vector<pair<string ,int>> wordVec;
        for(auto iter = wordCount.begin(); iter != wordCount.end(); iter++){
            wordVec.push_back(pair<string,int>(iter->first, iter->second));
        }
        sort(wordVec.begin(), wordVec.end(), compareCount);
        vector<string> res;
        for(int i = 0; i < k && i < wordVec.size() ;i++){
            res.push_back(wordVec[i].first);
        }
        return res;
    }
};
// @lc code=end

