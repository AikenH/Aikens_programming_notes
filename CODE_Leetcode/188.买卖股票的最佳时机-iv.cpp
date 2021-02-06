/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */

#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.empty()) return 0;
        int n = prices.size();
        // BUY 表示已经持有股票的情况
        // SELL 表示手上啥都没有的情况
        k = min(k,n/2);
        vector<vector<int>> DPBuy(n,vector<int>(k+1));
        vector<vector<int>> DPSell(n,vector<int>(k+1,0));
        // basecase;

        DPBuy[0][0] = -prices[0];
        for(int i = 1;i<=k;i++){
            DPBuy[0][i] = DPSell[0][i] = INT_MIN/2; // 由于我们还要减去一些值，所以这里小但是也不要小的太过分
        }
        // ++ i 和i++ 在for循环里面是一样的，但是性能上在大量使用的时候++更好一些。
        for(int i = 1;i<n;i++)
        {
            // 为什么这个时候要用作-price[I]
            DPBuy[i][0] = max(DPBuy[i-1][0],-prices[i]);
            for(int j = 1;j<=k;j++)
            {
                // 只在购买添加操作数，不在卖出添加炒作书
                DPBuy[i][j] = max(DPBuy[i-1][j], DPSell[i-1][j]-prices[i]);
                DPSell[i][j] = max(DPSell[i-1][j],DPBuy[i-1][j-1]+prices[i]);
            }
        }
        return *max_element(DPSell[n-1].begin(),DPSell[n-1].end());
    }
};
// @lc code=end

