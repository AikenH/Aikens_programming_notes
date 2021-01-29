/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        // 实现将word1 变成 word2
        // auto w1_it = word1.rbegin();
        // auto w2_it = word2.rbegin();
        // 首先使用递归的方式实现一下这个问题，然后再用迭代的方式做
        int w2_idx = word2.size();
        int w1_idx = word1.size();
        // 存储表实现：vector 长度初始化学起来(主要需要存储一个空值所以记得后面的index要加1)
        vector<vector<int>> memo(w1_idx+1,vector<int>(w2_idx+1,0));
        // 初始状态初始化
        for(int i =0; i<memo.size();i++)
            memo[i][0] = i;
        for(int j =0; j<memo[0].size();j++)
            memo[0][j] = j;
        // 正向迭代 bottom-up
        // 实际上从A-》B的变换和从b——》A的变换是对称的，不用太纠结方向的问题
        for(int i =1;i<memo.size();i++)
        {
            for(int j=1;j<memo[0].size();j++)
            {
                // FIXME：操作是存在象征意义的，所以不是都在最后才+1的
                // memo[i][j] = min(memo[i][j-1],memo[i-1][j]);
                // memo[i][j] = min(memo[i][j],memo[i][j-1]);
                int minv = 500;
                if(word1[i-1] == word2[j-1])
                {
                    minv = memo[i-1][j-1];
                    // memo[i][j] = memo[i-1][j-1];
                }
                // 减少对数组的操作实际上运行时间会减少。
                minv = min(minv,memo[i-1][j-1]+1);
                minv = min(minv,memo[i-1][j]+1);
                memo[i][j] = min(minv,memo[i][j-1]+1);
                // memo[i][j] = min(memo[i][j],memo[i-1][j]+1);
                // memo[i][j] = min(memo[i][j],memo[i-1][j-1]+1);
                // memo[i][j] = min(memo[i][j],memo[i][j-1]+1);
            }
        }
        return memo[w1_idx][w2_idx];

    }

    
};
// @lc code=end

