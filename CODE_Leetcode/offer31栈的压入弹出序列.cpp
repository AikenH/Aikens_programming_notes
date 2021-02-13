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
//我思考的解决思路：就是通过index来索引，当index变化的时候说明发生了一次转向，当合理的转向次数被应用，就能还原到原本的序列
//但是实际上这样的方法还涉及到搜索和index排序的问题，就很不好，而面对这样单体难以解决的问题，我们应该可以设计一个辅助的数据结构体来帮助我们解决，这是一个常见的思路。
//那么如果我们使用一个新的栈来解决这样的问题的话，这样的思路是很直接的，也就是基于一个栈来对另一个栈的动作进行指导，
//我们可以知道栈的输入和输出就是反向的，所以我们可以通过不断的压入，当遇到另一个栈底元素再开始pop，然后看能否还原这个过程

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if (pushed.size() != popped.size()) return false;
        int tempindexj = 0;
        stack<int> pushedlike;
        for (int i = 0; i < pushed.size(); i++) {
            pushedlike.push(pushed[i]);
            if (pushed[i] == popped[tempindexj]) {
                while(pushedlike.top()==popped[tempindexj]){
                    pushedlike.pop(); 
                    tempindexj++;
                    //FIXME 下面这两条代码很重要才能通过，说明我的代码种存在一定的问题。逻辑不够好
                    if (tempindexj >= popped.size()) break;
                    if (pushedlike.empty()) break;
                }
            }
        }
        if (!pushedlike.empty() || tempindexj < popped.size()) return false;
        return true;
    }
};

// -----------------------------------------test--------------------------------
// 在这个地方编写测试样例并进行测试；
int main()
{
    std::cin.get();
}