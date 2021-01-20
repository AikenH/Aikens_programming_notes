/*leetcode中算法的测试样板
*/
#include<vector>
#include<unordered_map>
// -----------------------------------------question--------------------------
输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。
示例 1：
输入：head = [1,3,2]
输出：[2,3,1]
限制：
0 <= 链表长度 <= 10000

// -----------------------------------------ans--------------------------------
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //效果很差，继续优化
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> ans;
        reverseAdd(head, ans);
        return ans;
    }
    void reverseAdd(ListNode* head, vector<int>& vet){
        // 没有对空值进行判断
        //没有设置迭代的终止条件，大忌
        //可以整合在一起
        if(head == nullptr)
            return;

        reverseAdd(head->next, vet);
        vet.push_back(head->val);
 
    }
};
// -----------------------------------------ans2--------------------------------

class Solution {
public:
    //究极拉跨，比上面的迭代还要拉跨，为啥？
    // vector<int> ans;
    // vector<int> reversePrint(ListNode* head) {
        
    //     if(head == nullptr)
    //         return ans;
    //     reversePrint(head->next);
    //     ans.push_back(head->val);
        
    //     return ans;
    // }
// -----------------------------------------ans3--------------------------------
// 反转的方法，速度和ans1差不多；但是内存占用最小
    vector<int>res;
        while(head){
            res.push_back(head->val);
            head = head->next;
        }
        //使用algorithm算法中的reverse反转res
        reverse(res.begin(),res.end());
        return res;
};
// -----------------------------------------ans4--------------------------------
class Solution {
public:
    //速度目前最快，内存占用第二
    vector<int> reversePrint(ListNode* head)
    {
        stack<int> s;
        //入栈
        while(head){
            s.push(head->val);
            head = head->next;
        }
        //出栈
        while(!s.empty()){
            res.push_back(s.top());
            s.pop();
        }
        return res;
    }
};
// -----------------------------------------test--------------------------------
// 在这个地方编写测试样例并进行测试；
int main()
{
    // [] , [1,3,4]
    std::cin.get();
}