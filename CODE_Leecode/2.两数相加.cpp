/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        return helpadd(l1,l2,0) ;
    }
    ListNode* helpadd(ListNode* l1, ListNode* l2, int s)
    {
        if (!l1 && !l2 && !s)
            return nullptr;
        int sum = (l1 ? l1->val : 0) + (l2? l2->val : 0) + s;
        ListNode* node1 = new ListNode(sum % 10);
        node1->next = helpadd(l1?l1->next:nullptr, l2?l2->next:nullptr, sum / 10);
        return node1;
    }
};
// @lc code=end

