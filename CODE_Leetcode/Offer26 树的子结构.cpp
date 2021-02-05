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
// 这题一定要好好的梳理一下，这题在首先的函数的递归思路还是比较特别的情况
class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(!A || !B) return false;
        // 分成两步去做：1. 首先找到和B的根节点一样的值，然后进行搜索；
        bool ans = false;
        if(A->val == B->val) ans = helpJudge(A,B);
        // NOTE：这里的这种递归模式还是一种比较有意思的情况，学起来
        if(!ans) ans = isSubStructure(A->left,B);
        if(!ans) ans = isSubStructure(A->right,B);
        
        return ans;
    }
    bool helpJudge(TreeNode* temp, TreeNode* B){
        if(!B) return true;
        if(!temp) return false; // 排除了第一种情况以后的任意一种情况。
        if(temp->val != B->val) return false;
        // 如果上面那个没满足就相当于是后面的满足相等就相等了
        return helpJudge(temp->right, B->right) && helpJudge(temp->left, B->left);
    }
};

    
// -----------------------------------------test--------------------------------
// 在这个地方编写测试样例并进行测试；
int main()
{
    std::cin.get();
}