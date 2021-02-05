/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换 II
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    // 完全背包问题，看看官方的解说，对于单题来说解决的挺好的，但是我们要分析这样分析的原因
    // 这题是真的狗，到底怎么去构建这个动态增长的最优过程，也就是状态和状态转移，是最难的地方
    // 最难的思考点在于到底是怎么排除掉重复计算可能性的情况？
    // FIXME：主要在于第二个分支，他一定用到了新增进来的这个值，所以和上面的情况不可能出现重复
    // 而基于假设就是所有的情况这种情况，就能将所有的列举额出来，给老子细细品味这个
    int change(int amount, vector<int>& coins) {
        if(!amount) return 1;
        int n = coins.size();
        // 初始化
        // vector<vector<int>> DP (n+1, vector<int>(amount+1,0));
        // for (int i = 0;i<=n;i++) DP[0][i] = 0;
        // for (int i = 0;i<=n;i++) DP[i][0] = 1;
        vector<int> DP (amount+1,0);
        DP[0] =1;
        // 进行迭代操作（后续进行压缩简化）
        for (int i = 1; i<=n;i++){
            for(int j = 1;j<=amount;j++){
                // if(j<coins[i-1]) DP[i][j] = DP[i-1][j];
                // if(j<coins[i-1]) DP[j] = DP[j];
                // else
                if(j>=coins[i-1])
                    DP[j] = DP[j] + DP[j-coins[i-1]];
                    // 核心点所在，但是这种情况为什么会遍历到所有的情况要自己搞明白。
                    // 实际上还是递归的n-1的假设，假设n-1的情况能够被完全的数出来。
            }
        }
        return DP[amount];
    }
};
// @lc code=end

