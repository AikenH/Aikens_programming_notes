/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 */

// @lc code=start
class Solution {
public:
    // NOTE：实际上这个fee加在哪都可以，但是如果加在-的部分，记得在初始化也加上
    int maxProfit(vector<int>& prices, int fee) {
        if(prices.empty()) return 0;
        // vector<vector<int>> dp(prices.size(),vector<int>(2));
        int dpi_0 = 0; int dpi_1 = -prices[0];
        for(int i=1;i<prices.size();i++){
            // 这里没有限制k 怎么限制呢，把那个改成0
            int temp = dpi_0;
            dpi_0 = max(dpi_0,dpi_1+prices[i]-fee);
            dpi_1 = max(dpi_1,temp-prices[i]);
            // cout<<dp[i][0] <<"  "<<dp[i][1]<<endl;

        }
        return dpi_0;
    }
};
// @lc code=end

