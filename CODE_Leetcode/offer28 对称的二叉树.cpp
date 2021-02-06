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
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        // 两点要求：1. 结构对称 2. 数据对成
        /* 实现思路：使用某种遍历格式，然后使用该遍历的左右对称格式，然后每一步都需要相等 
                    这一题主要是对二叉树的遍历框架进行一个复习，但是问题是二元的框架如何操作*/  
        if(!root) return true;
        return helpSymmtric(root->left, root->right);      
    }
    bool helpSymmtric(TreeNode* leftNode, TreeNode* rightNode){
        // FIXME:这一题的二元前序遍历框架还是有点意思的。
        if(!leftNode && !rightNode) return true;
        if(!leftNode || !rightNode) return false;
        if(leftNode->val != rightNode->val) return false;
        return helpSymmtric(leftNode->left, rightNode->right) && \
                helpSymmtric(leftNode->right,rightNode->left);
    }
};
// -----------------------------------------test--------------------------------
// 在这个地方编写测试样例并进行测试；
int main()
{
    std::cin.get();
}