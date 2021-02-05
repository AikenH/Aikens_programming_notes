/*
 * @lc app=leetcode.cn id=319 lang=cpp
 *
 * [319] 灯泡开关
 */

// @lc code=start
class Solution {
public:
    int bulbSwitch(int n) {
        return (int)sqrt(n);
    }
};
// @lc code=end

// 这一题同样也是，这个分析问题的思路挺有意思的，实际上是一个数学题把，但是正常的解怎么做也要学下。
// 首先很简单的能想到是一个因式分解的问题，然后通过对问题的转化，可以知道可以转化成一个找小于N的完全平方数的问题，那么开个根号就行了。