/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        // 使用快慢指针，不一样的时候再替换即可
        int l=0, r=1;
        int n = nums.size();
        while(r<n){
            if(nums[r] != nums[l]){
                nums[++l] = nums[r];
            }
            r++;
        }
        return l+1;
    }
};
// @lc code=end

