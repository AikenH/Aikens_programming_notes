/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        // 后续可以尝试一下自顶向下的写法，这种写法比较傻逼，但是也可以尝试掌握
        // 这题不用贪心算法的话，后面有个很恶心的东西不让做
        // 下面这是基本的自底向上的方法，
        int n = nums.size();
        int end = 0, farthest = 0;
        int jumps = 0;
        for (int i = 0; i < n - 1; i++) {
            farthest = max(nums[i] + i, farthest);
            if (end == i) {
                jumps++;
                end = farthest;
            }
        }
        return jumps;

    }
};
// @lc code=end

