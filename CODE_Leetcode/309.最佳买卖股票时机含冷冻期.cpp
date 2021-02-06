/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 最佳买卖股票时机含冷冻期
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        // vector<vector<int>> dp(prices.size(),vector<int>(2));
        int dpi_0 = 0; int dpi_1 = -prices[0]; int temp_pre=0;
        for(int i=1;i<prices.size();i++){
            // 这里没有限制k 怎么限制呢，把那个改成0
            int temp1 = dpi_0;
            dpi_0 = max(dpi_0 ,dpi_1 +prices[i]);
            dpi_1 = max(dpi_1 ,temp_pre-prices[i]);
            // cout<<dp[i][0] <<"  "<<dp[i][1]<<endl;
            temp_pre = temp1;
        }
        return dpi_0;
    }
};
// @lc code=end

