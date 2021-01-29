/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */

// @lc code=start
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // 分析一下basecase
        // bottom-up 等下写一下递归的框架
        int m = text1.size(), n = text2.size();
        // 我们分析可以知道，我们按照3个方向进行搜索的话，一开始会存在溢出，所以
        // 我们不妨牺牲一点点空间来换取每一步都需要判断的 不必要的运算时间
        vector<vector<int>> dpTable (m,vector<int>(n,-1));
        // // TODO: 存储空间压缩
        // for (int i = 1;i<=m;i++){
        //     for(int j = 1;j<=n;j++){
        //         if(text1[i-1]==text2[j-1])
        //             dpTable[i][j] = 1+ dpTable[i-1][j-1];
        //         else
        //             dpTable[i][j] = max(dpTable[i-1][j], dpTable[i][j-1]);
        //     }
        // }
        // return dpTable[m][n];
        
        return dp(text1,m-1,text2,n-1,dpTable);
    }
    
    int dp(string s1, int i, string s2, int j, vector<vector<int>>& dpTable ){
        if (i == -1 ||j == -1)
        {
            return 0;
        }
        if(dpTable[i][j] != -1)
            return dpTable[i][j];
        if(s1[i] == s2[j])
            dpTable[i][j] = dp(s1,i-1,s2,j-1,dpTable) +1;
        else
            dpTable[i][j] = max(dp(s1,i,s2,j-1,dpTable),dp(s1,i-1,s2,j,dpTable));
        return dpTable[i][j];
    }
};
// @lc code=end

