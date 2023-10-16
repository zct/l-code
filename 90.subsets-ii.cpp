/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 */

// @lc code=start
#include <set>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
/*
class Solution {
public:

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > res;
        if(nums.size() == 0 ){
            return res;
        }
        res.push_back(vector<int>{});
        res.push_back(vector<int>{nums[0]});
        for(int i = 1; i <nums.size(); i++){
            // if(nums[i] == nums[i-1]){
            //     vector<int> sameVec;
            //     for(int j = 0; j <i; j++){
            //         sameVec.push_back(nums[j]);
            //     }
            //     res.push_back(sameVec);
            // } else {
                res = dp(res, nums[i], false);
            // }
        }
        return res;
    }

    vector<vector<int> > dp(vector<vector<int> >& prev, int j, bool skip) {
        set<vector<int> > dedupSet;
        vector<vector<int> > vecRes;
        for(auto iter = prev.begin(); iter != prev.end(); iter++) {
            dedupSet.insert(*iter);
        }
        vector<vector<int> > vecCombine;
        for(auto iter = dedupSet.begin(); iter != dedupSet.end(); iter++){
            vector<int> tempVec = *iter;
            tempVec.push_back(j);
            vecCombine.push_back(tempVec);
        }
        for(auto iter = vecCombine.begin(); iter != vecCombine.end(); iter++){
            dedupSet.insert(*iter);
        }
        dedupSet.insert(vector<int>{j});

        for(auto iter = dedupSet.begin(); iter != dedupSet.end(); iter++){
            vecRes.push_back(*iter);
        }
        return  vecRes;
    }
};*/
class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        this->nums = nums;
       /* int startIndex = 0;
        dfs(false, 0);
        return res;*/
        vector<int> used(nums.size(), 0);
        vector<int> subarray;
        backtracking(0, subarray, used);
        return res;
    }

    void backtracking(int idx, vector<int>& subarray, vector<int>& used){
        res.push_back(subarray);
        for(int i = idx; i < nums.size(); i++){
            if(i>0 && nums[i] == nums[i-1] && !used[i-1]){
                continue;
            }
            subarray.push_back(nums[i]);
            used[i] = true;
            backtracking(i+1,  subarray, used);
            subarray.pop_back();
            used[i] = false;
        }
    }

    void dfs(bool choosePre, int startIndex)
    {
        if (startIndex == nums.size())
        {
            res.push_back(path);
            return;
        }
        dfs(false, startIndex + 1);
        if (!choosePre && startIndex > 0 &&
            nums[startIndex] == nums[startIndex - 1])
        {
            return;
        }
        path.push_back(nums[startIndex]);
        dfs(true, startIndex + 1);
        path.pop_back();
    }

private:
    vector<int> nums;
    vector<vector<int>> res;
    vector<int> path;
};
// int main() {
//     Solution s;
//     vector<int> b= vector<int> {4,4,4,1,4};
//     vector<vector<int> > a = s.subsetsWithDup(b);
//     for(auto iter = a.begin(); iter != a.end(); iter++){
//         cout << *iter << endl;
//     }
// }
// @lc code=end

