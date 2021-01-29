/*
 * @lc app=leetcode.cn id=516 lang=cpp
 *
 * [516] 最长回文子序列
 */
#include<string>
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        // 画那种二维图能够帮助分析是真的，
        // 考虑到我们常规情况下的回文判断是通过两侧拓展实现的
        // 我们在这里也执行增加的两侧相等时进行判断，其他时候借助于状态转移
        // if (s.size()==0) return 0;
        int n = s.size();
        int res = 1;
        // 初始化DP Table 显然子序列的长度应该是大于0的，至少得有一个，所以
        vector<vector<int>> DpTable(n,vector<int>(n,0));
        for (int i=0;i<n;i++)
        {
            DpTable[i][i] =1;
        }
        // NOTE：这里为了确保下面和旁边都有值，需要更改一下迭代的方向
        for(int i=n-2;i>=0;i--)
        {
            for (int j=i+1;j<n;j++)
            {
                // 由于我们给越界值添加了0，所以不用考虑越界的情况
                if(s[i]==s[j])
                    DpTable[i][j]=DpTable[i+1][j-1] + 2;
                else 
                    DpTable[i][j] = max(DpTable[i+1][j],DpTable[i][j-1]);
            }
        }
        return DpTable[0][n-1];
    }
};
// @lc code=end

