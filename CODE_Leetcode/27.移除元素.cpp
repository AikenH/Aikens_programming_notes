/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.empty()) return {};
        int n = nums.size();
        int be = 0, en =n-1;
        // 使用双指针法解决这个问题，也就是不一样的时候进行交换
        while(be<=en){
            if(nums[be]!=val){
                ++be;
            }
            else if(nums[en]==val){
                --en;
            }
            else{
                swap(nums[be],nums[en]);
            }
        }
        return en+1;
    }
};
// @lc code=end

