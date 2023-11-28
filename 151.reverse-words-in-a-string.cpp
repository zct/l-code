/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
 class Solution {
public:
    string reverseWords(string s) {
        bool remainSpace = false;
        vector<string> vecStr;
        int len = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
            {
                if (!remainSpace && len != 0)
                {
                    vecStr.push_back(s.substr(i - len, len));
                    remainSpace = true;
                    len = 0;
                }
                continue;
            }
            else
            {
                remainSpace = false;
                len++;
            }
        }
        if (!remainSpace)
        {
            vecStr.push_back(s.substr(s.size() - len, len));
        }
        string sRes;
        for (int i = vecStr.size() - 1; i >= 0; i--)
        {
            sRes.append(vecStr[i]);
            if (i != 0)
            {
                sRes.append(1, ' ');
            }
        }
        return sRes;
    }
};
// @lc code=end

