/*
 * @lc app=leetcode.cn id=752 lang=cpp
 *
 * [752] 打开转盘锁
 */

// @lc code=start
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        // 使用回溯法遍历所有的可能性,同时做出特殊的终结判断
        // 同时维护一个最小值,然后最终返回.

        // 正确理解题目的意思(每次只能转动单个转盘,而且只能移动一格)
        // 为什么使用BFS,最短路径,找到了就提前终止,同时是路径问题
        
    }
};
// @lc code=end

