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
// 主要就是使用后续遍历去做，没啥了。避免重复，虽然还有一些奇怪的地方
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        bool res = true; //用于保存判定结果
        getDepth(root, 0, res);
        return res;
    }
    int getDepth(TreeNode* root, int depth, bool & res)
    {
        if(root == NULL)
            return depth; //到达叶子节点的下一层，直接返回当前深度
        ++depth; //当前层数
        int tmp1 = getDepth(root->left, depth, res); //获得左右子树深度的最大值
        int tmp2 = getDepth(root->right, depth, res);

        if(tmp1 - tmp2 >1 || tmp2 - tmp1 >1) //左右子树的最大深度差大于1,即不满足平衡条件
            res = false;
        return max(tmp1, tmp2); //解题关键
    }                                                                                                                                                                                                                                                  
};

// -----------------------------------------test--------------------------------
// 在这个地方编写测试样例并进行测试；
int main()
{
    std::cin.get();
}