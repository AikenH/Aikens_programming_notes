/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
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
class Solution {
public:
    void flatten(TreeNode* root) {
        helpflat(root);
    }
    TreeNode* helpflat(TreeNode* root){
        if(!root)
            return nullptr;
        TreeNode* lefte = helpflat(root->left);
        TreeNode* righte = helpflat(root->right);
        if(!lefte && !righte)
            return root;
        else if(righte && !lefte)
        {
        }
        else
        {
            lefte->right = root->right;
            root->right = root->left;

        }
        root->left = nullptr;
        return righte?righte:lefte;
    }
};
// @lc code=end

