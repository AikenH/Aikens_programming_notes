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
class MinStack{
private:
    stack<int> s1;
    stack<int> smin;
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        s1.push(x);
        if (smin.empty() || x<=smin.top()) smin.push(x);
    }

    void pop() {
        if (s1.top() == smin.top()) {
            smin.pop();
        }
        s1.pop();
    }

    int top() {
        return s1.top();
    }

    int min() {
        return smin.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */

// -----------------------------------------test--------------------------------
// 在这个地方编写测试样例并进行测试；
int main()
{
    std::cin.get();
}