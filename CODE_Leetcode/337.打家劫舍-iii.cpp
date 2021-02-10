/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
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
private:
    unordered_map<TreeNode*, int> DP;
public:
    int rob(TreeNode* root) {
        if(!root) return 0;
        if(DP.find(root)!= DP.end()) return DP[root];
        // if(DP.contains(root)) return DP[root];
        int robres = rob(root->left)+ rob(root->right);
        int unrobres = root->val;
        unrobres += !root->left? 0: (rob(root->left->left) +rob(root->left->right));
        unrobres += !root->right? 0: (rob(root->right->left) + rob(root->right->right));
        int res = max(robres, unrobres);
        DP[root] = res;
        return res;
    }
};
// @lc code=end

