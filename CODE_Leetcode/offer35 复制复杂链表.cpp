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
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return {};

        // 初始化起始节点
        unordered_map<Node*, Node*> hashtable;
        Node* NewHead = new Node(head->val);
        hashtable[head] = NewHead;
        // 复制起始节点的备份
        Node* tempori = head;
        // Node* res = NewHead;
        // 按照next形式修改
        head = head->next;
        // 首先按照next构造一下链表
        while (head) {
            NewHead->next = new Node(head->val);
            NewHead = NewHead->next;
            hashtable[head] = NewHead;
            head = head->next;
        }
        head = tempori;
        // 根据hashtable建立random索引；
        // NOTE:这里的索引记得是指向新的节点，不要忘了
        while (head) {
            hashtable[head]->random = hashtable[head->random];
            head = head->next;
        }
        return hashtable[tempori];
    }

};
// -----------------------------------------test--------------------------------
// 在这个地方编写测试样例并进行测试；
int main()
{
    std::cin.get();
}