#
# @lc app=leetcode.cn id=3 lang=python
#
# [3] 无重复字符的最长子串
#

# @lc code=start
# TODO：时间和空间复杂度都不达标(用if和判断)但是改成max以后效率上升了很多
# TODO：思考第二种解法，用set的hash相关的方法。
# 官方思路和解法，感觉和hash表有关
# https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/solution/wu-zhong-fu-zi-fu-de-zui-chang-zi-chuan-by-leetc-2/

class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        list1 = []
        maxlen,templen = 0, 0
        for i in s:
            if i not in list1:
                list1.append(i)
                templen += 1 
            else:
                # 从重复位开始删除
                maxlen = max(templen,maxlen)
                list1 = list1[(list1.index(i)+1):]
                list1.append(i)
                templen = len(list1)
        maxlen = max(templen,maxlen)
        return maxlen
# @lc code=end

