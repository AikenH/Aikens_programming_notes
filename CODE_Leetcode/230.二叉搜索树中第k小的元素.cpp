/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
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
private:
    int count = 0;
    int res = INT_MIN;
public:
    int kthSmallest(TreeNode* root, int k) {
        traverr(root,k);
        return res;
    }
    void traverr(TreeNode* root, int k){
        if (!root)
            return;
        traverr(root->left,k);
        count++;
        if(count==k)
            res = root->val;
        traverr(root->right,k);
    }
};
// @lc code=end

