#
# @lc app=leetcode.cn id=9 lang=python
#
# [9] 回文数
#

# @lc code=start
class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        # solution 1 ： 字符串 解法
        # runtime beat  98.69%
        # return str(x)[::-1] == str(x)

        # soulution2 : 进阶解法，不使用字符串的情况
        # 很显然的回文数，只需要从一半进行颠倒就行了，参考整形反转的方法去做
        # NOTE: 0 结尾的也不可能是回文数
        if x < 0 or (x % 10 == 0 and x != 0): return False
        else:
            # 分奇数和偶数的情况进行分析
            # 但是如果还要提前计算出数据的位数的话就显得有点多余了 👇
            ans = 0 
            while x > ans:
                ans = ans * 10 + x % 10 
                if ans == x : return True
                x = x // 10
        # 考虑到为0的特殊情况，不能直接简单的return false
        return ans == x
# @lc code=end

# NOTE：7-8-9 是同一类别的问题，基本上是一致的