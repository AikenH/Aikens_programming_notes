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
        vector<int> dpTable (n+1, 0);
        
        for (int i =1;i<=m;i++)
        {
            int pre = 0; // 这个初始化的问题也很重要，在每一个i的最早的时候的basecase
            for (int j = 1; j<=n;j++)
            {
                int temp = dpTable[j];
                if(word1[i-1] == word2[j-1])
                    dpTable[j] = pre +1;
                else
                    dpTable[j] = max(dpTable[j], dpTable[j-1]);
                pre = temp;
            }
        }
        
        return  -2*dpTable[n] + m + n ;

    }
};
// @lc code=end

