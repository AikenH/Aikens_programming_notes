/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.empty()) return ;
        int n = nums.size();
        int slow=0, fast =0;
        // 使用双指针法解决这个问题，也就是不一样的时候进行交换
        while(fast<n){
            if(nums[fast]!=0){
                nums[slow] = nums[fast];
                if(slow != fast) nums[fast] =0;
                ++slow;
            }
            fast++;
        }
    }
};
// @lc code=end

