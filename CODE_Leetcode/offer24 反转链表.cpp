/*leetcode中算法的测试样板
*/
#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<queue>
using namespace std;
// -----------------------------------------question--------------------------

// -----------------------------------------ans--------------------------------
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !(head->next)) return head;
        ListNode* NewHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return NewHead;
    }
};
// -----------------------------------------test--------------------------------
// 在这个地方编写测试样例并进行测试；
int main()
{
    std::cin.get();
}