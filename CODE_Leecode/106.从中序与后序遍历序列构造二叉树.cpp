/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
 // run time 达标了，但是memory use差了很多
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helpbuild(inorder.begin(),inorder.end(),postorder.begin(),postorder.end());

    }
    TreeNode* helpbuild(vector<int>::iterator ins,vector<int>::iterator ine,
                        vector<int>::iterator pos, vector<int>::iterator poe)
    {
        if(poe == pos)
            return nullptr;
        // 这里要注意的是end是有值的下一项
        // iterator 之间的加减和index之间的加减的关系的转化也要清楚到底是怎么回事
        poe--;
        TreeNode* cur = new TreeNode(*poe);
        auto root = find(ins,ine,*poe);
        cur->left = helpbuild(ins,root,pos,poe-(ine-root-1));
        cur->right = helpbuild(root+1,ine,poe-(ine-root-1),poe);
        return cur;

    }
};
// @lc code=end

