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
        # TODO:参考参考答案中的哈希方法同时学习一下



# @lc code=end

