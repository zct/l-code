/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 */

// @lc code=start
#include <string>
#include <vector>

using namespace std;

string sayStringToNum(string input)
{
    if (input.size() == 0)
        return 0;
    string result;
    vector<string> sVec;
    char prev = input[0];
    int repeatNum = 1;
    for (int i = 1; i < input.size(); i++)
    {
        if (input[i] != prev)
        {
            sVec.push_back((std::to_string(repeatNum) + std::string(1, prev)));
            prev = input[i];
            repeatNum = 1;
            continue;
        }
        repeatNum++;
    }
    sVec.push_back((std::to_string(repeatNum) + std::string(1, prev)));
    for (auto iter = sVec.begin(); iter != sVec.end(); iter++)
    {
        result += *iter;
    }
    return result;
}

class Solution
{
public:
    string countAndSay(int n)
    {
        if (n == 1)
            return "1";
        string s = countAndSay(n - 1);
        return sayStringToNum(s);
    }
};
// @lc code=end
