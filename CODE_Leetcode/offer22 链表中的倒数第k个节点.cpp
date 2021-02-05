/*leetcode中算法的测试样板
*/
#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<queue>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
// -----------------------------------------question--------------------------

// -----------------------------------------ans--------------------------------
class Solution {
private:
    int count = 0;
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        // 我的两种想法，一种是使用一个Quene，通过满和替换，来执行
        // 2是通过后续遍历，当计数为k时候输出
        // 书上的方法是双指针来解决的
        if(!head) return head;
        ListNode* res = getKthFromEnd(head->next,k);
        count++;
        if(count == k)
            res = head;
        return res;
    }
};
// -----------------------------------------test--------------------------------
// 在这个地方编写测试样例并进行测试；
int main()
{
    std::cin.get();
}