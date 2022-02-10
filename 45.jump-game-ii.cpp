/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        
        vector<int> f(nums.size());
        for(auto i = 0; i< nums.size(); i++){
            f[i] = nums.size();
        }
        f[0] = 0;
        for(auto i = 0; i < nums.size();i++){
            for(auto j  = 1; j <= nums[i]; j++){
                if((i+j) < nums.size()){
                    f[i+j] = min(f[i+j], f[i]+1);
                }
            }
        }
        return f[nums.size()-1];
    }
    
};
// @lc code=end

