/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return {};
        ListNode* pre = head;
        ListNode* movep = head->next; 
        // 和上面26题完全一样，就是换了个写法
        while(movep){
            if(pre->val != movep->val){
                pre->next->val = movep->val;
                pre = pre->next;
            }
            movep = movep->next;
        }
        pre->next = nullptr;
        return head;
    }
};
// @lc code=end

