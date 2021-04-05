/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return nullptr;
        // 要考虑到删除的节点如果是head的情况
        int count = 0; ListNode* slow = head; ListNode* fast = head;
        // 要考虑到越界的情况
        while(count<n){
            if(!fast) return nullptr;
            fast = fast->next;
            
            ++count;
        }
        ListNode* prev;
        while(fast){
            prev = slow;
            fast = fast->next;
            slow = slow->next;
        }
        if(slow != head)
            prev->next = slow->next;
        else
            return head->next;
        return head;
    }
};
// @lc code=end

