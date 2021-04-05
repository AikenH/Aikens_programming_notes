/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 */

// @lc code=start


//  struct ListNode {
//      int val;
//      ListNode *mext;
//      ListNode() : val(0), next(nullptr) {}
//      ListNode(int x) : val(x), next(nullptr) {}
//      ListNode(int x, ListNode *next) : val(x), next(next) {}
//  };

// class Solution {
// public:
//     ListNode* reverseKGroup(ListNode* head, int k) {
//         ListNode* start, *end;
//         start = end = head;
//         for (int i = 0; i<k;i++)
//         {
//             if(end == nullptr)
//                 return head;
//             end = end->next;
//         }
//         ListNode* newH = reversek(start,end);
//         start->next = reverseKGroup(end,k);
//         return newH;
//     }
//     ListNode* reversek(ListNode* start, ListNode* end)
//     {
//         ListNode* curr = start; 
//         ListNode* prev = nullptr; //最后的赋值再下一行，哪个start.net
//         while(curr!=end)
//         {
//             ListNode* temp = curr;
//             curr = curr->next;
//             temp->next= prev;
//             // curr.next= temp; 多做了一部，我们只做到当前curr指向的点就行
//             prev = temp; 
//         }
//         return prev;
//     }
// };
class Solution 
{
public:
    ListNode* reverseKGroup(ListNode* head, int k){
        // 首先找到第k个的头和尾巴，问题来了，能不能在进行反转的时候顺便进行统计呢？
        // k = 0的时候记录一个起点，然后一路反转到K，然后在K的时候，给头赋值到下一个，用递归的方式
        // 等下写写看
        ListNode* end = head;
        int count = 0;
        while(count<k){
            if(!end) return head;
            end = end->next; // 要判断是不是空
            count++;
        }
        ListNode* newHead = reverse(head,end);
        head->next = reverseKGroup(end,k); // 这里是个坑
        return newHead;

    }
    ListNode* reverse(ListNode* head, ListNode* tail){
        // 因为我们要k个一组的反转linknode，所以这里一定有个头尾的概念
        // 反转链表的时候我们这次测试一下别的写法。
        // 如果使用下一个的下一个的话判断起来好像比较玛法
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr != tail){
            ListNode* temp = curr;
            curr = curr->next;
            temp->next = prev;
            prev = temp;
        }
        return prev;
    }
};

// @lc code=end

