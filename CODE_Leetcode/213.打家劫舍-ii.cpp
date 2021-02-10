/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        /* 实际上分析也就是稍微修改一下上面一题的代码
        就是只需要要么只有头要么只有尾，上一题的代码都可以重用 */
        if(nums.empty()) return 0;
        // 只有一个的也要考虑
        int n = nums.size();
        if(n == 1) return nums[0];
        return max(helprob(nums,1,n-1), helprob(nums, 0, n-2));
    }
    int helprob(vector<int> nums, int start, int end)
    {
        int n = end - start + 1;
        int dp0 = 0; int dp1 = nums[start];
        for(int i = 1;i<n;i++)
        {
            int temp = dp1;
            dp1 = max(dp0+nums[start+i],dp1);
            dp0 = temp;
        }
        return dp1;
    }
};
// @lc code=end

