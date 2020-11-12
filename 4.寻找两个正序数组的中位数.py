#
# @lc app=leetcode.cn id=4 lang=python
#
# [4] 寻找两个正序数组的中位数
#
# NOTE: 考验的应该是排序和搜索算法
# NOTE: memory use这个指标需要留意吗
# TODO：复习：时间复杂度的计算，排序和搜索的经典算法
# TODO：基于该时间复杂度，完成计算过程（感觉我应该在复杂度之内啊）
# @lc code=start
class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        # 首先做出两种判断，排除极端情况
        total = len(nums1)+ len(nums2)
        # train_itera = total // 2 if total%2!=0 else total // 2 + 1
        train_itera = total // 2 + 1
        # NOTE：实际上可以加入两种不同情况下的考虑，应该能在某些情况下进一步减少复杂度
        # 但是好像没这个必要
        # 此外下面的代码好像有一部分是存在问题的

        # if min(nums1[0],nums2[-1]) == nums2[-1]:
        #     for i in range(train_itera-1):
        #         if nums2:
        #             ans = nums2[0]
        #             nums2.pop(0)
        #         else:
        #             ans = nums1[0]
        #             nums1.pop(0)
        #     if nums2:
        #         ans = nums2[0] if total%2 != 0 else (ans+nums2[0])/2.0
        #     else:
        #         ans = nums1[0] if total%2 != 0 else (ans+nums1[0])/2.0
        
        # elif max(nums1[-1],nums2[0]) == nums2[0]:
        #     for i in range(train_itera-1):
        #         if nums1:
        #             ans = nums1[0]
        #             nums1.pop(0)
        #         else:
        #             ans = nums2[0]
        #             nums2.pop(0)
        #     if nums1:
        #         ans = nums1[0] if total%2 != 0 else (ans+nums1[0])/2.0
        #     else:
        #         ans = nums2[0] if total%2 != 0 else (ans+nums2[0])/2.0
            
        # else:
        #     # 前两种情况都不需要排序，第三种情况需要对数列进行排序处理
        for i in range(train_itera-1):
            if nums1 and nums2:
                if nums1[0] < nums2[0]:
                    ans = nums1[0]
                    nums1.pop(0)
                else:
                    ans = nums2[0]
                    nums2.pop(0)
            elif nums1:
                ans = nums1[0]
                nums1.pop(0)
            else:
                ans = nums2[0]
                nums2.pop(0)
        
        if total % 2 != 0:
            try:
                ans = min(nums1[0],nums2[0])
            except IndexError:
                ans = nums1[0] if nums1 else nums2[0]
        else:
            try:
                ans += min(nums1[0],nums2[0])
            except IndexError:
                ans += nums1[0] if nums1 else nums2[0]
            ans = ans / 2.0

        return ans
# @lc code=end

