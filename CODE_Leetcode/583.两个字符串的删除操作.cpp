/*
 * @lc app=leetcode.cn id=583 lang=cpp
 *
 * [583] 两个字符串的删除操作
 */

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        // 这题换句话说不就是找到最长的公共子序列吗？
        int m = word1.length(), n = word2.length();
        vector<vector<int>> dpTable (m+1, vector<int>(n+1, 0));
        for (int i =1;i<=m;i++)
        {
            for (int j = 1; j<=n;j++)
            {
                if(word1[i-1] == word2[j-1])
                    dpTable[i][j] = dpTable[i-1][j-1] +1;
                else
                    dpTable[i][j] = max(dpTable[i-1][j], dpTable[i][j-1]);
            }
        }
        
        return  -2*dpTable[m][n] + m + n ;

    }
};
// @lc code=end

