/*leetcode中算法的测试样板
*/
#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<queue>
using namespace std;
struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//Definition for singly-linked list.
struct ListNode {
   int val;
   ListNode* next;
   ListNode(int x) : val(x), next(NULL) {}
};

// -----------------------------------------question--------------------------

// -----------------------------------------ans--------------------------------
/* 这题实际上思路上就是一个很简单的中序遍历的思想，但是我们怎么获取到当前的pre也就是前面的链表的尾巴的思想
还有我们到底是要return还是使用void的两种方法我们要好好的分析
网友在这里的题解更是清楚明确，同时思路上也值得我们借鉴，书上的解法不知道为什么问题一大堆，虽然基本的思路上是一致的不改了，自己运行没问题 */
class Solution {
public:
    Node* treeToDoublyList(Node* root)
    {
        if (root == NULL)    return NULL;
        inorder(root);
        head->left = pre;   //链表头的前驱指向链表尾
        pre->right = head;  //链表尾的后继指向链表头
        return head;
    }
private:
    Node* pre = NULL;   //前驱节点
    Node* head = NULL;  //双向链表的头节点
    void inorder(Node* cur)
    {
        if (cur == NULL)    return;
        inorder(cur->left);
        //当前前驱节点为空，说明这是双向链表的头节点（树中最左节点）
        if (pre == NULL)
            head = cur;
        //此时已有前驱，说明这是链表中的某个中间节点，将前驱的右指针指向cur
        else
            pre->right = cur;
        //把cur（当前节点）的左指针指向其前驱
        cur->left = pre;
        //当前节点成为前驱
        pre = cur;
        //递归结束后，pre指向链表的尾节点
        inorder(cur->right);
    }
};
// -----------------------------------------test--------------------------------
// 在这个地方编写测试样例并进行测试；
int main()
{
    std::cin.get();
}