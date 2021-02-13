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
// z 字形打印我们可以根据输出顺序发现可以使用栈的数据结构
// 而我们需要使用两个栈，因为用栈的话，另一个还不pop完的时候就要压入了。
// 通过顺序画图，我们可以知道这种反序的操作很多时候可以借助栈的特性来实现。
// -----------------------------------------ans--------------------------------
//没什么好说的，典型的BFS的题目
class Solution {
private:
    /*bool l2r = true;*/
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        stack<TreeNode*> s1; // 先l后r的压入s2
        stack<TreeNode*> s2; // 先r后l的压入s1
        vector<vector<int>> res;
        //初始化变量
        s1.emplace(root);
        while (!s1.empty() || !s2.empty()) {
            vector<int> tempvalue;
            if (!s1.empty()) {
                while (!s1.empty()) {
                    tempvalue.emplace_back(s1.top()->val);
                    if (s1.top()->left) s2.push(s1.top()->left);
                    if (s1.top()->right) s2.push(s1.top()->right);
                    s1.pop();
                }
                res.emplace_back(tempvalue);
                continue;
            }
            if (!s2.empty()) {
                while (!s2.empty()) {
                    tempvalue.emplace_back(s2.top()->val);
                    if (s2.top()->right) s1.push(s2.top()->right);
                    if (s2.top()->left) s1.push(s2.top()->left);
                    s2.pop();
                }
                res.emplace_back(tempvalue);
                continue;
            }

        }
        return res;
    }
};
// -----------------------------------------test--------------------------------
// 在这个地方编写测试样例并进行测试；
int main()
{
    std::cin.get();
}