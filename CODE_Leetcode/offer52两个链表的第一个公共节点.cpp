/*leetcode中算法的测试样板
*/
#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<string>
#include<queue>
#include<set>
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
/*双指针让走到的长度对等。  */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *node1 = headA;
        ListNode *node2 = headB;
        
        while (node1 != node2) {
            node1 = node1 != NULL ? node1->next : headB;
            node2 = node2 != NULL ? node2->next : headA;
        }
        return node1;
    }
};

/* 用set直接单次遍历的方法 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*,int> m;
        while(headA)  
        {
            ++m[headA];
            headA = headA->next;
        }  
        while(headB)    
        {
            if(m[headB])    return headB;
            headB = headB->next;
        }
        return NULL;
    }
};



/* 统计长度的方法 */
public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
    //统计链表A和链表B的长度
    int lenA = length(headA), lenB = length(headB);

    //如果节点长度不一样，节点多的先走，直到他们的长度一样为止
    while (lenA != lenB) {
        if (lenA > lenB) {
            //如果链表A长，那么链表A先走
            headA = headA.next;
            lenA--;
        } else {
            //如果链表B长，那么链表B先走
            headB = headB.next;
            lenB--;
        }
    }

    //然后开始比较，如果他俩不相等就一直往下走
    while (headA != headB) {
        headA = headA.next;
        headB = headB.next;
    }
    //走到最后，最终会有两种可能，一种是headA为空，
    //也就是说他们俩不相交。还有一种可能就是headA
    //不为空，也就是说headA就是他们的交点
    return headA;
}

//统计链表的长度
private int length(ListNode node) {
    int length = 0;
    while (node != null) {
        node = node.next;
        length++;
    }
    return length;
}

作者：sdwwld
链接：https://leetcode-cn.com/problems/liang-ge-lian-biao-de-di-yi-ge-gong-gong-jie-dian-lcof/solution/ji-he-shuang-zhi-zhen-deng-3chong-jie-jue-fang-shi/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
// -----------------------------------------test--------------------------------
// 在这个地方编写测试样例并进行测试；
int main()
{
    std::cin.get();
}