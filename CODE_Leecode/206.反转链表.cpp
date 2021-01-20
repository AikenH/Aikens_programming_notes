/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 // NOTE：迭代方法
// 使用两个指示器：不要害怕这个空间损失，先把解题的思路清除，做出来再说
// 一个指向之前的位置，一个指向当前的位置，当前的后移，然后把临时的原本指向以前，再把以前的后裔
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr)
        {
            ListNode* temp = curr;
            curr = curr->next;
            temp->next = prev;
            prev = temp;
        }
        return prev;

    }
};

// TODO：递归解法：
// 递归问题的分析过程中可以把已经完成的n-1，而我们处于n的情况画一下，然后进行分析
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //FIXME:注意考虑了末端的情况还要考虑空表的情况
        // 注意head空的判断要在headnext的前面
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode* newhead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr; 
        return newhead;

    }
};
// @lc code=end

// 附加任务：反转链表的前N个节点
class Solution 
{
public:
    ListNode* last = nullptr;
    ListNode* reverseList(ListNode* head, int n)
    {
        if(n == 1)
        {
            last = head->next;
            return head;
        }
        ListNode* tail = reverseList(head->next, n-1);
        head->next->next = head; //新的尾部节点了
        head->next = last;
        return tail;
    }
};