#
# @lc app=leetcode.cn id=5 lang=python
#
# [5] 最长回文子串
#
# 需要分析的情况有如下三种 abcba bb|bbbb abba 
# @lc code=start
# Solved : 一大长串重复的字符的运算时间超出了限制，case的method上应该是没问题的。
# NOTE： 加入一个一致性判断，从而优化大量重复子串的运行时间 （Sameflag）
class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        # defind the judge boundary , and how many times we can itera
        allowrange = [0,0]
        maxstr = ''
        for i in range(len(s)):
            # 向左右允许迭代的最大值
            maxstr =s[i] if len(maxstr)<1 else maxstr
            allowrange = [i-0, len(s)-i-1]
            # 由于我们采取的是基于中心的搜索策略，所以搜索到做小边界的+1即可
            # 根据3种不同的情况进行分析和迭代，
            left,right = 0,0
            # breakflag = False
            sameflag = True
            while left<allowrange[0] or right<allowrange[1]:
                if i-left-1 < 0:
                    break
                elif i + right +2 > len(s):
                    if s[i-left-1] ==  s[i-left] and sameflag:
                        # for v in s[i-left-1:i+right+1]:
                        #     if v != s[i-left]: 
                        #         breakflag =True
                        #         break
                        # if breakflag: break
                        left += 1
                    else:
                        break
                else:
                    if s[i-left-1] == s[i+right+1]:
                        left, right = left+1, right+1
                        if sameflag and s[i-left] != s[i]:
                            sameflag =False
                    elif s[i-left-1] == s[i-left] and sameflag:
                        # 进行判断的过程，当只加入单侧，就需要判断是否每个值是相同的
                        # for v in s[i-left-1:i+right+1]:
                        #     if v != s[i-left-1]: 
                        #         breakflag = True
                        #         break
                        # if breakflag:break
                        left += 1 
                    else:
                        break
                if len(s[i-left:i+right+1]) > len(maxstr):
                    maxstr = s[i-left: i+right+1]
        return maxstr

# @lc code=end

# TODO: 复习时空复杂度的计算方法
# TODO: 对所有编写的算法计算时空复杂度
# TODO: 回顾动态规划的定义和Code Process
if __name__ == "__main__":
    A = Solution()
    print(A.longestPalindrome('222020221'))