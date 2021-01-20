/*
 * @lc app=leetcode.cn id=652 lang=cpp
 *
 * [652] 寻找重复的子树
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
 // TODO:这题可以讨论一下python的解法，应该会更简单一点。
 // FIXME：这题目前这样的结果十分的差，后序看看其他方法的改进，但是这题的解题思路还是很不错
#include <unordered_map> 
#include <string>
class Solution {
public:
    unordered_map<string,int> memo;
    vector<TreeNode*> res;
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        if(!root)
            return {}; // 这个返回值要记得
        traverse(root);
        return res;
    }
    string traverse(TreeNode* root){
        if(!root)
            return "#";
        string left = traverse(root->left);
        string right = traverse(root->right);
        // 得到一个后序遍历的序列，（但是基于这样的序列怎么判断子树一致呢？）
        // FIXME int到string的转换到底怎么做，好疑惑啊。
        char temp = root->val +'0';
        string resstr = left + "," + right+"," + temp;
        // 压入hashmap,但是普通的压入的话，会导致多个重复的root；
        // 那么如果我们对memo用map管理的话，就只有==1的时候
        // FIXME：为什么contains不能用
        if(memo.count(resstr))
            memo[resstr]++;
        if (memo[resstr]==1)
            res.push_back(root);
        return resstr;
    }
};
// @lc code=end

