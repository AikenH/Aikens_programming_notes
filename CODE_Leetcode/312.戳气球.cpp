/*
 * @lc app=leetcode.cn id=312 lang=cpp
 *
 * [312] 戳气球
 */

// @lc code=start
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {        
        if(nums.empty()) return 0;
        // 首尾不包含
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int n = nums.size();
        // 加了两个之后的size
        vector<vector<int>> DP(n,vector<int>(n,0));
        // 从下往上遍历，从左往右遍历
        for(int i = n-2; i>=0;i--)
        {
            for(int j =i+1; j<n; j++)
            {
                for(int k =i+1;k<j;k++)
                {
                    DP[i][j] = max(DP[i][j], nums[k]*nums[i]*nums[j]+DP[i][k]+DP[k][j]);
                }

            }
        }
        return DP[0][n-1];
    }
};
// @lc code=end

