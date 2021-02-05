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
    
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        // NOTE：需要一个新的head的时候可以这么操作。
        ListNode* tempHead;
        if(l1->val<l2->val){
            tempHead = l1; 
            tempHead->next = mergeTwoLists(l1->next,l2);
        }else{
            tempHead = l2;
            tempHead->next = mergeTwoLists(l1,l2->next);
        }
        return tempHead;
    }
};
// -----------------------------------------test--------------------------------
// 在这个地方编写测试样例并进行测试；
int main()
{
    std::cin.get();
}