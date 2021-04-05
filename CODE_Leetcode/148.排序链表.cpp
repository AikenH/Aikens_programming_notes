/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
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
    ListNode* sortList(ListNode* head) {
        return helpsort(head,nullptr);

    }
    ListNode* helpsort(ListNode* head, ListNode* tail){
        // 实际上就是归并排序的解决方式，考虑top-down和bottom-up两种方法
        // 首先使用快慢指针来做top-down的方法
        if(!head) return nullptr;
        // 构建只有单一值的时候的base cases，最后肯定会一直切分到这种情况；
        // 为了merge，我们是不是应该将其next设定为nullptr
        if(head->next == tail) {
            head->next = nullptr;
            return head;
        }
        ListNode* fast = head; ListNode* slow = head;
        // 可以通过fast的状态来判断奇偶，但是这一题不需要这点
        while(fast!=tail && fast->next!=tail){
            fast = fast->next->next;
            slow = slow->next;
        }
        // 不断的分裂然后进行merge = 进行排序，但是这里涉及到的切分，我们需要修改一下
        ListNode* left = helpsort(head,slow);
        ListNode* right = helpsort(slow,tail);
        return helpMerge(left, right);
    }
    ListNode* helpMerge(ListNode* left, ListNode* right){
        if(!left) return right;
        if(!right) return left;
        ListNode* newroot = new ListNode(0); // 最后返回他的下一个值，为的就是方便
        ListNode* res = newroot; // 浅拷贝地址
        //一个一个接下取
        while(left && right){
            if(left->val > right->val){
                newroot->next = right;
                right = right->next;
            }else{
                newroot->next = left;
                left = left->next;
            }
            newroot = newroot->next;
        }
        if(left) newroot->next = left;
        else if (right) newroot->next = right;
        return res->next;
    }
};
// @lc code=end

