/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
// class Solution {
// public:
//     // ListNode* head;
//     ListNode* left;
//     bool isPalindrome(ListNode* head) {
//         this->head = head;
//         return reverseJ(head);
//     }
//     bool reverseJ(ListNode* tail){
//         // 我们虽然可以通过后序遍历来首先取到链表的tail
//         // 但是我们如何让最底层的取到的也是最前面的head呢？（需要另一一个共有head）
//         if (tail == nullptr)
//             return true;
//         bool ans = reverseJ(tail->next);
//         ans = ans && (this->head->val == tail->val);
//         this->head = this->head->next;
//         return ans;
//     }
// };

// 稍微修改一下上面的方法，不用this的话，速度会提升不少，所以没必要哦
class Solution {
public:
    ListNode* left;

    bool isPalindrome(ListNode* head) {
        left = head;
        return traverse(head);
    }

    bool traverse(ListNode* right) {
        if (right == nullptr) return true;
        bool res = traverse(right->next);
        // 后序遍历代码
        res = res && (right->val == left->val);
        left = left->next;
        return res;
    }
};
// @lc code=end
class Solution {
public:
    ListNode *fast, *slow;
    bool isPalindrome(ListNode* head)
    {
        fast = slow = head;
        while(fast!=nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        if (fast!=nullptr)
            slow = slow->next;
        ListNode* right = reverse(slow);
        while(right != nullptr)
        {
            if (head->val != right->val)
                return false;
            head = head->next;
            right = right->next;
        }
        return true;
    }
    ListNode* reverse(ListNode* head)
    {
        ListNode *curr, *prev, *temp;
        curr = head; prev = nullptr;
        while(curr!=nullptr)
        {
            temp = curr;
            curr = curr->next;
            temp->next = prev;
            prev = temp;
        }
        return prev;
    }
    
};
