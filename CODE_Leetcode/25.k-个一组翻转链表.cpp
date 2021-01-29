/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* start, *end;
        start = end = head;
        for (int i = 0; i<k;i++)
        {
            if(end == nullptr)
                return head;
            end = end->next;
        }
        ListNode* newH = reversek(start,end);
        start->next = reverseKGroup(end,k);
        return newH;
    }
    ListNode* reversek(ListNode* start, ListNode* end)
    {
        ListNode* curr = start; 
        ListNode* prev = nullptr; //最后的赋值再下一行，哪个start.net
        while(curr!=end)
        {
            ListNode* temp = curr;
            curr = curr->next;
            temp->next= prev;
            // curr.next= temp; 多做了一部，我们只做到当前curr指向的点就行
            prev = temp; 
        }
        return prev;
    }
};
// @lc code=end

