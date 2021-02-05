/*
 * @lc app=leetcode.cn id=292 lang=cpp
 *
 * [292] Nim 游戏
 */

// @lc code=start
class Solution {
public:
    bool canWinNim(int n) {
        // 主要是找题目的规律，明确获胜和失败的条件之间的区别；
        if(n%4 == 0)
            return false;
        return true;
    }
};
// @lc code=end

// 同理的还有取巧的石头游戏等等的问题，先手可以选择拿走奇数或者偶尔堆；
// 但是实际上还是可以用石头问题来构建一个博弈情况下的动态规划设计的问题。