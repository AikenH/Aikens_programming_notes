/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
#include<queue>
using namespace std;

class Solution {
private:
    // int res = INT_MAX;
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode *, int>> q;
        // 初始化队列起点
        q.emplace(root,1);
        while(!q.empty()){
            // int sz = q.size();
            // for(int i=0;i<sz;i++){
            TreeNode *temp = q.front().first;
            int depth = q.front().second;
            if(!temp->right && !temp->left)
                return depth;
            if(temp->left != nullptr)
                q.emplace(temp->left, depth+1);
            if(temp->right != nullptr)
                q.emplace(temp->right,depth+1);
            q.pop();
            // }
        }
        return 0;
    }
    // void helpFind(TreeNode* root, int step){
    //     // 是没有子节点的节点，也就是左右节点都没有要注意区分
    //     if(!root){
    //         // if(step<res) 
    //         //     res = step;
    //         return;
    //     }
    //     step++;
    //     if(!root->left && !root->right)
    //     {
    //         if(step<res) res = step;
    //         return;
    //     }
    //     helpFind(root->right,step);
    //     helpFind(root->left,step);
        
    // }
};
// @lc code=end

