#
# @lc app=leetcode.cn id=2 lang=python
#
# [2] 两数相加
#

# @lc code=start
# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def addTwoNumbers(self, l1:ListNode, l2:ListNode):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        s = 0
        # output = ListNode()
        while l1 or l2 or s:
            temp = ((l1 if l1 else 0)+(l2 if l2 else 0)+ s)//10
            s = temp//10
            output = 

            
# @lc code=end

