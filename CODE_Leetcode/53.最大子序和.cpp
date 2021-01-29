/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
class Solution {
public:
    // O(n^2暴力求解)
    int maxSubArray(vector<int>& nums) {
        // 基本思路，要么和前面的并，要么自己从头开始
        // 只需要三个值来存储就行，
        int maxvalue = nums[0];
        int premax = nums[0];
        int tempvalue = nums[0];
        for (int i = 1;i<nums.size();i++){
            tempvalue = nums[i] + premax;
            if (tempvalue > nums[i])
                premax = tempvalue;
            else
                premax = nums[i];
            if (premax > maxvalue)
                maxvalue = premax;
        }
        return maxvalue;
    }
};
// @lc code=end

