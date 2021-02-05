/*leetcode中算法的测试样板
*/
#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<queue>
using namespace std;
// -----------------------------------------question--------------------------
给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。

返回删除后的链表的头节点。

注意：此题对比原题有改动

示例 1:

输入: head = [4,5,1,9], val = 5
输出: [4,1,9]
解释: 给定你链表中值为 5 的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -> 1 -> 9.
示例 2:

输入: head = [4,5,1,9], val = 1
输出: [4,5,9]
解释: 给定你链表中值为 1 的第三个节点，那么在调用了你的函数之后，该链表应变为 4 -> 5 -> 9.
 

说明：

题目保证链表中节点的值互不相同
若使用 C 或 C++ 语言，你不需要 free 或 delete 被删除的节点

// -----------------------------------------ans--------------------------------
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
 

//解决方式入口函数, 运行时间是随缘的有点时候这个直接99 93可
class Solution {
public:
    
    ListNode* deleteNode(ListNode* head, int val) {
        
        // 普通做法, 但是这题又曲解了原书的意思，所以无法使用原书的替换算法。但是要理解书上的内容
        if (!head) return nullptr;
        if (head->val == val) return head->next;
        ListNode* root = head;
        while (root && root->next) {
            if (root->next->val == val)
            {
                root->next = root->next->next;
                break;
            }
            root = root->next;
        }
        return head;
        
    }
};
// 也可以使用双指针的写法 会快一些。
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if (head == NULL) {  //  特判
            return NULL;
        }
        if (head->val == val) {  //  头节点为要删除的节点
            return head->next;
        }

        ListNode* cur = head;  //  当前节点
        ListNode* pre = head;  //  保存删除节点的前一节点
        while (cur != NULL && cur->val != val) {
            pre = cur;
            cur = cur->next;
        }
        if (cur != NULL) {
            pre->next = cur->next;
        }

        return head;
    }
};
// -----------------------------------------test--------------------------------
// 在这个地方编写测试样例并进行测试；
int main()
{
    std::cin.get();
}