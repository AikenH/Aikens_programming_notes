/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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
// FIXME:为什么在这里使用迭代器的方法会出现很多问题，无法进行实现，正确的写法应该是怎么杨的？
// lvalue来初始化一个node我知道不行，但是为什么会是左值呢。
// class Solution {
// public:
//     TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
//         TreeNode* root = helpbuild(nums.begin(),nums.end());
//         return root;
//     }
//     TreeNode* helpbuild(vector){
//         int max= *begin;
//         for(vector<int>::iterator it=begin; it!=end; it++){
//             if(*it>max)
//                 max = *it;
//         }
//         cout<<max<<endl;
//         TreeNode* inner; 
//         inner->val = max;
//         auto next = find(begin,end,max);
//         inner->left = helpbuild(begin,next);
//         inner->right = helpbuild(next+1,end);
//         return inner;

//     }
// };
class Solution{
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return helpbuild(nums,0,nums.size());
    }
    TreeNode* helpbuild(vector<int>& nums, int begin, int end){
        if(nums.empty() || begin==end)
            return nullptr;
        int maxindex = -1, maxval = INT_MIN;
        for(int i=begin;i<end;i++){
            if (nums[i]>=maxval)
            {
                maxindex = i;
                maxval = nums[i];
            }
        }
        // inner的生存周期问题
        TreeNode* inner = new TreeNode(maxval);
        inner->left = helpbuild(nums,begin,maxindex);
        // 下面这里没有+1的画，会导致一个机器严重的问题，但是我不知道为啥，是溢出了把，永远无法到达终点？
        inner->right = helpbuild(nums,maxindex+1,end);
        return inner;
    }
};
// @lc code=end

