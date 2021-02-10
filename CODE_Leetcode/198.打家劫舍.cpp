/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        // 两个相邻的房屋无法取到实际上就是一个简单的状态转移的问题；
        int n = nums.size();
        // vector<int> DP(n+1,0);
        // 实际上就是一个单项的偷盗图
        // BaseCases
        // DP[0] = 0;
        // DP[1] =nums[0]; 
        // for(int i=2;i<=n;i++){
        //     DP[i] = max(nums[i-1]+ DP[i-2], DP[i-1]); 
        // }
        // return DP[n];
        // 基于参数的特性进行存储空间优化
        int d0 = 0; int d1 = nums[0];
        
        for(int i =1;i<n;i++){
            int temp = d1;
            d1 = max(d0 + nums[i], d1);
            d0 = temp;
        }
        return d1;
    }
};
// @lc code=end

