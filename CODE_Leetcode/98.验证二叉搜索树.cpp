/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
// FIXME:为什么使用NULL的方法会失效。
// LONG的使用情景，
// 试着用迭代的方式去写（中序遍历）
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return helpJudge(root,LONG_MAX,LONG_MIN);
    }
    bool helpJudge(TreeNode* root, long int max,long int min){
        if(!root)
            return true;
        // 这个大于等于等于号不能丢掉。
        if(root->val >= max) return false;
        if(root->val <= min) return false;
        // 根据节点往下迭代的情况，更新最小值和最大值，因为右侧的最小值是不断增长的
        // 而左侧的最大值是在不断的变小的。这一点是这个问题最关键的地方
        return helpJudge(root->right,max,root->val) && helpJudge(root->left,root->val,min);
    }
};
// @lc code=end

