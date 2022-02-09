/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start

#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> res;
        map<int,int> indexMap;
        auto index = 1;
        for(auto iter = nums.begin(); iter != nums.end(); iter++)
        {
            indexMap[*iter] = index++;
        }
        
       for(auto i = 0; i < nums.size(); i++) {
           if(indexMap[target-nums[i]] != 0 && (indexMap[target-nums[i]]-1) != i){
               res.push_back(i);
               res.push_back(indexMap[target-nums[i]]-1);
               return res;
           }
       }
        return res;
        
    }
};

// @lc code=end
