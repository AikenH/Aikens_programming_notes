/*leetcode中算法的测试样板
*/
#include<vector>
#include<unordered_map>
// -----------------------------------------question--------------------------
//输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
//例如，给出
//
//前序遍历 preorder = [3, 9, 20, 15, 7]
//中序遍历 inorder = [9, 3, 15, 20, 7]
//返回如下的二叉树：
//
//  3
// /  \
//9   20
//    / \
//  15   7
//限制：
//0 <= 节点个数 <= 5000
//注意：本题与主站 105 题重复：https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

// -----------------------------------------ans--------------------------------
struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 这是目前最优的一个解法了，是使用一个迭代的方法，当然我们可以利用4个指针的移动来实现一样的迭代效果。
// 但是会使用额外的空间存储把，
class Solution 
{
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        // int tempre[preorder.size()];
        // 函数，返回一个迭代器
        return helpbuild(preorder.begin(),preorder.end(),inorder.begin(),inorder.end());
    }
    // 学，给老子学，怎么在c++中实现动态数组的划分传入，如果是python可太爽了；
    TreeNode* helpbuild(vector<int>::iterator preb, vector<int>::iterator prend, \
        vector<int>::iterator inob, vector<int>::iterator inoe)
    {
        if(inob == inoe)
            return nullptr;
        TreeNode* cur = new TreeNode(*preb);
        // 记住这个函数find，返回的是一个迭代器，迭代器本身就是一个指针，指针的+1会随着类型的不同而变化
        auto root = std::find(inob,inoe,*preb);
        cur->left = helpbuild(preb+1,preb+(root-inob)+1,inob,root);
        cur->right = helpbuild(preb+(root-inob)+1,prend,root+1,inoe);

        return cur;
    }
};
// -----------------------------------------test--------------------------------

// 在这个地方编写测试样例并进行测试；
// 应该有什么测试样例，空子树，一边空，一边不空，之类的，
int main()
{

    std::cin.get();
}
// NOTE：知识点分析：
/*
1. find 和vector的关系和return为迭代器
2. 迭代器实际上也是一个指针（指向第一个元素？因为是连续的所以？）；值是当前位置的值
3. 迭代器的加减（指针的加减）实际上应该是被重载过，也就是+ - 会跟随type来进行在内存空间上的移动，而不是直接移动一格
4. vector的实现：是不是和智能指针一样指针域存储在stack上所以连续；还是说+-实际上是重载了指针的指向操作，链表式的？
5. 使用迭代器类型来对vecrtor本身的指针进行利用，来节省存储空间，不需要重新定义新的几个指针来指向那几个地址（难道要用指针的指针？）
6. 递归算法本身的n-1 假设以及 初值，停止条件的思想。
7. end指向的是下一个位置而不是当前的位置，所以在计算距离的时候要清楚。（还有前闭后开的思想）

a. 利用前序和中序实现重建的思想要深入琢磨一下，来确定这种思维范式；
b. 设定测试样例对于树来说确实特别的不熟悉，还是需要看看。
*/