#
# @lc app=leetcode.cn id=2 lang=python
#
# [2] 两数相加
#

# @lc code=start
# Definition for singly-linked list.
# TODO: try to figure out why the memory use is too much 
# TODO: find out out way to solve this problem
# TODO: Familiar with the idea and writing of recursion
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        return self.search(l1,l2,0)

    def search(self,r,v,i):
        if not r and not v and not i: return None
        temp = (r.val if r else 0) + (v.val if v else 0) + i
        node = ListNode(temp%10)
        node.next = self.search(r.next if r else 0, v.next if v else 0, temp//10)
        return node

# if __name__ == "__main__":
#     print(Solution.addTwoNumbers(123,234))


# @lc code=end

