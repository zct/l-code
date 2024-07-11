/*
 * @lc app=leetcode id=1 lang=java
 *
 * [1] Two Sum
 */

// @lc code=start
import java.util.HashMap;

class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> numMap = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
                numMap.put(nums[i], i);
        }
        System.out.println(numMap);
        int[] result = new int[2];
        for (int i = 0; i < nums.length; i++) {
            if (numMap.containsKey(target - nums[i]) && numMap.get(target-nums[i]) != i) {
                result[0] = i;
                result[1] = numMap.get(target - nums[i]);
                break;
            }
        }
        return result;
    }
}
// @lc code=end

