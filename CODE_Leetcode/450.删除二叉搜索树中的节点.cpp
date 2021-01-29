/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// class Solution {
// public:
//     TreeNode* deleteNode(TreeNode* root, int key) 
//     {
//         // 首先找到节点的上一个节点，然后根据匹配节点的子节点的不同情况
//         // 单个子节点，无子节点，双子节点（要搜索到左侧的最右来替换，右侧的最左来替换）
//         // 怎么排除第一个节点（怎么样不用排除这个节点）
//         // if(!root)
//         //     return nullptr;
//         // if (root->val == key)
//         // {
//         //     TreeNode* curr = root;
//         //     TreeNode* temp;
//         //     while (curr->right->right)
//         //         curr = curr->right;
//         //     // 对当前节点的子节点进行了一个继承，切换root节点。
//         //     temp = curr;
//         //     curr->right->left = root->left;
//         //     curr->right->right = root->right;
//         //     root->left = root->right = nullptr;
//         //     // 切换尾部节点。下面这一段好像可以被替换
//         //     curr->right = temp->right->left;
//         // }
//         // else
//         //     return helpdele();
//         if (!root)
//             return root;
//         if (root->val == key)
//         {
//             // 叶节点或者是只有单边有节点的情况
//             // 没搞懂，为什么这就叫做删除了。
//             if(!root->right)
//             {
//                 return root->left;
//             }
//             else if (!root->left)
//             {
//                 return root->right;
//             }
//             else
//             {
//                 // 找到左子树的最右节点
//                 TreeNode* LeR = root->left;
//                 while(LeR->left)
//                     LeR = LeR->right;
//                 TreeNode* tmp = root;
//                 LeR->right = root->right;
//                 root = root->left; //直接无视掉原本的节点我真尼玛太骚了。
//                 delete tmp;
//                 return root; 
//             }
            
//         }
//         if(root->val >key) 
//             root->left = deleteNode(root->left ,key);
//         if(root->val< key)
//             root->right = deleteNode(root->right, key);
//         return root;
//     }
//     // TreeNode* helpdele(TreeNode* root, int key)
//     // {
//     //     // 递归的去解决这个问题

//     // }
// };
class Solution {
public:
    //把左子树直接整个接到右子树的后面去，这样确实实现起来比较方便
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return root; // 第一种情况：没找到删除的节点，遍历到空节点直接返回了
        if (root->val == key) {
            // 第二种情况：左右孩子都为空（叶子节点），直接删除节点， 返回NULL为根节点
            // 第三种情况：其左孩子为空，右孩子不为空，删除节点，右孩子补位 ，返回右孩子为根节点
            if (root->left == nullptr) return root->right; 
            // 第四种情况：其右孩子为空，左孩子不为空，删除节点，左孩子补位，返回左孩子为根节点
            else if (root->right == nullptr) return root->left; 
            // 第五种情况：左右孩子节点都不为空，则将删除节点的左子树放到删除节点的右子树的最左面节点的左孩子的位置
            // 并返回删除节点右孩子为新的根节点。
            else {  
                TreeNode* cur = root->right; // 找右子树最左面的节点
                while(cur->left != nullptr) { 
                    cur = cur->left;
                }
                cur->left = root->left; // 把要删除的节点（root）左子树放在cur的左孩子的位置
                TreeNode* tmp = root;   // 把root节点保存一下，下面来删除
                root = root->right;     // 返回旧root的右孩子作为新root
                delete tmp;             // 释放节点内存（这里不写也可以，但C++最好手动释放一下吧）
                return root;
            }
        }
        if (root->val > key) root->left = deleteNode(root->left, key);
        if (root->val < key) root->right = deleteNode(root->right, key);
        return root;
    }
};

// @lc code=end

