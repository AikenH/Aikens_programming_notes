/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 */

// @lc code=start

//Definition for singly-linked list.
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };
// 实际上这样的一个方式是递归转化的思路，将起始的限制转化到尾部去；
// 这种解题思想也是要学一下的，但是其实也可以再加一个约束，保留前置的样本，然后后面还是递归到n）
class Solution 
{
private:
    ListNode* last = nullptr;
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == 1)
        {
            return reverseN(head, n);
        }
        head->next = reverseBetween(head->next, m - 1, n - 1);
        // 这里，return head和递归之间的关系要掌握好，从变换的阈值开始分析，比较传入值和return值就知道了
        return head;
    }
    ListNode* reverseN(ListNode* head, int n)
    {
        if (n == 1)
        {
            last = head->next;
        }
        ListNode* tail = reverseN(head->next, n - 1);
        head->next->next = head;
        head->next = last;
        return tail;
    }
};
// @lc code=end

