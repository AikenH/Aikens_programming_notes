/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /* 实际上如果起始点后面的数没有其实点小的话，
        就没必要计算了，因为最大值不会超过这 */
        if(prices.empty()) return 0;
        // int maxvalue = 0; // 可以不买入，就至少不会亏钱
        // int buy = prices[0];
        // for(int j=1;j<prices.size();j++)
        // {
        //     maxvalue = max(maxvalue, prices[j]-buy);
        //     if (prices[j]<buy) buy = prices[j];
        // }
        // return maxvalue;

        vector<vector<int>> dp(prices.size(),vector<int>(2));
        dp[0][0] = 0; dp[0][1] = -prices[0];
        for(int i=1;i<prices.size();i++){
            // 这里没有限制k 怎么限制呢，把那个改成0
            dp[i][0] = max(dp[i-1][0],dp[i-1][1]+prices[i]);
            dp[i][1] = max(dp[i-1][1],-prices[i]);
            // cout<<dp[i][0] <<"  "<<dp[i][1]<<endl;

        }
        return dp[prices.size()-1][0];

    }
};
// @lc code=end

