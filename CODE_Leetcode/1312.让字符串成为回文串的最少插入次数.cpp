/*
 * @lc app=leetcode.cn id=1312 lang=cpp
 *
 * [1312] 让字符串成为回文串的最少插入次数
 */

// @lc code=start
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    int minInsertions(string s) {
        if(s.empty()) return 0;
        int n = s.size();
        // 建立存储表和初始化参数（单个或者是边界都是0）
        // vector<vector<int>> DP(n,vector<int>(n,0));
        // // 遍历方向，从从下到上，从左到右
        // for(int i=n-2; i>=0; i--){
        //     for(int j=i+1; j<n; j++){
        //         // 搜先判断延拓的情况是是否是相等的
        //         if(s[i] == s[j]) DP[i][j] = DP[i+1][j-1];
        //         else DP[i][j] = min(DP[i+1][j], DP[i][j-1]) +1;
        //     }
        // }
        // return DP[0][n-1];

        vector<int> DP(n,0);
        for(int i=n-2; i>=0; i--){
            int pre = 0;
            for(int j=i+1; j<n; j++){
                // 搜先判断延拓的情况是是否是相等的
                int temp = DP[j]; // 到下一轮编程i+1 j-1的值 ，在本轮是i+1，j的值（未更新）
                if(s[i] == s[j]) DP[j] = pre;
                else DP[j] = min(DP[j], DP[j-1])+1;
                pre = temp; // 
            }
        }
        return DP[n-1];
    }
};
// @lc code=end

