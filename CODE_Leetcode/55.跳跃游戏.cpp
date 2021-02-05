/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    // 这题主要需要我们脑子清醒，很明晰那，《最远距离的就是我们的所有可达点（就算有0也会被绕过。），
    // 除非我们可达点无法再前进了（我们能走到的地方《=当前战力的位置），我们才false，不然我们就能一掷千金到终点
    bool canJump(vector<int>& nums) {
        int n  = nums.size();
        int farthest = 0;
        for (int i=0;i<n;i++)
        {
            farthest = max(farthest,i+nums[i]);
            if (farthest<=i) break;
        }
        return farthest>=(n-1);
    }
};
// @lc code=end

