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

