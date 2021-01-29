/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 用来判断是否两个点都存在在以如今的root所在的树中，如果存在的话就返回True
        // 设计的主要原则：
        // 1. 出现在了后面节点的左边和右边的话，就不可能出现在父节点的左边和右边
        // 2. 再叶节点找到相应的两个指，需要从后面遍历起来，先找到两个节点的位置，然后一级一级的并上来。
        if(!root)
            return nullptr;
        if(root == q || root == p)
            return root;

        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);

        if (left && right)
            return root;
        if (!left && !right)
            return nullptr; 
            
        return left?left:right;
    }
    // bool comexit(TreeNode* root, TreeNode* p, TreeNode* q);
};

// @lc code=end

