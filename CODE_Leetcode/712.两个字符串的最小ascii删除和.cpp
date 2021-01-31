/*
 * @lc app=leetcode.cn id=712 lang=cpp
 *
 * [712] 两个字符串的最小ASCII删除和
 */

// @lc code=start
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.length(), n = s2.length();
        vector<vector<int>> dpTable (m+1, vector<int>(n+1, 0));
        for (int i =1;i<=m;i++)
        {
            for (int j = 1; j<=n;j++)
            {
                if(s1[i-1] == s2[j-1])
                    dpTable[i][j] = dpTable[i-1][j-1] + (char)s1[i-1];
                else
                    dpTable[i][j] = max(dpTable[i-1][j], dpTable[i][j-1]);
            }
        }
        int sum = 0;
        for (char& ch: s1)
            sum += ch;
        for (char& ch: s2)
            sum += ch;
        return  -2*dpTable[m][n] + sum ;
    }
};
// @lc code=end

