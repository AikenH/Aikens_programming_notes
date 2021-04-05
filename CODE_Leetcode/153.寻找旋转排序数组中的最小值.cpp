/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
     
        // first of all write in a ez way
        for (int i = 0; i < nums.size()-1; i++) {
            // find first later< former
            if (nums[i + 1] < nums[i]) return nums[i + 1];
        }
        return nums[0];
        
    }
};
// @lc code=end

