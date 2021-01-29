#
# @lc app=leetcode.cn id=1 lang=python
#
# [1] 两数之和
#

# @lc code=start
class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        '''version 1 aiken ''' 
        # part1 --------------------------------
        j = -1
        for i in range(1,len(nums)):
            temp = nums[:i]
            if target-nums[i] in temp:
                j = temp.index(target-nums[i])
                break
        if j>=0:
            return[j,i]

        '''Version 2 to pay attention to :hash-related '''
        
        # 我上面写的这种方法实际上也是一种hash-like的写法了把。
        # 问题是不知道这个取index的函数的时间复杂度



# @lc code=end

