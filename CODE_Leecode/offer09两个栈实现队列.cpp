/*leetcode中算法的测试样板
*/
#include<vector>
#include<unordered_map>
#include<stack>
// -----------------------------------------question--------------------------
用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )

 

示例 1：

输入：
["CQueue","appendTail","deleteHead","deleteHead"]
[[],[3],[],[]]
输出：[null,null,3,-1]
示例 2：

输入：
["CQueue","deleteHead","appendTail","appendTail","deleteHead","deleteHead"]
[[],[],[5],[2],[],[]]
输出：[null,-1,null,null,5,2]
提示：

1 <= values <= 10000
最多会对 appendTail、deleteHead 进行 10000 次调用

// -----------------------------------------ans--------------------------------
template<typename T>
class CQueue {
private:
    std::stack<int> stack1;
    std::stack<int> stack2;
public:
    CQueue() {}
    
    void appendTail(int value) {
        stack1.push(value);
    }
    // 这种操作的时候需不需要进程锁之类的操作？
    int deleteHead() {
        if (stack2.empty())
        {
            while (!stack1.empty())
            {
                int temp = stack1.top();
                stack2.push(temp);
                stack1.pop();
            }
        }
        if (stack2.empty())
            return -1;
        int data = stack2.top();
        stack2.pop();
        return data;
        
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
// -----------------------------------------test--------------------------------
// 在这个地方编写测试样例并进行测试；
int main()
{
    std::cin.get();
}
/*
NOTE: 
1. leetcode中是否需要输入std，还是已经内置了using namespace std
2. 思考用队列模拟栈
*/