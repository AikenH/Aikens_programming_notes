/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> res;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        /* 实际上这题可以使用2.5种不同的思路去解决 
        1. 递归法：由于重叠子问题的存在和特殊性，（子问题的每一项加上新加入的一项）
        2. 回溯法：前序，也就是不断后移动start，然后逐个加入
        后续，使用pop出来的值来用（不是特别贴切）还是前一种好*/
        
        // 递归法
        // if(nums.empty()) return {{}};
        // int n = nums.back();
        // nums.pop_back();
        // vector<vector<int>> res = subsets(nums);
        // int size = res.size();
        // for(int i = 0; i <size; i++)
        // {
        //     res.emplace_back(res[i]);
        //     res.back().push_back(n);
        // }
        // return res;
        
        // 回溯法
        vector<int> tempv;
        int start = 0;
        backtrack(nums,tempv,0);
        return res;
        
    }
    void backtrack(vector<int>& nums,vector<int>& tempv, int start){
        res.push_back(tempv);
        int n = nums.size();
        for(int i=start; i<n; ++i){
            tempv.push_back(nums[i]);
            backtrack(nums,tempv,i+1);
            tempv.pop_back();
        }
        return ;

    }
};
// @lc code=end

