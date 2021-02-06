/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int n = prices.size();
        int s1 = -prices[0]; int s2 = 0; //我可以不买，所以一定是0不是int——min
        int s3 = INT_MIN; int s4 = 0; 
        for(int i =1;i<n;i++){
            s1 = max(s1, -prices[i]); //第一次买入可以任何时候
            s2 = max(s2, s1+prices[i]); // 在此刻第一次卖出
            s3 = max(s3, s2-prices[i]); // 第二次 买入
            s4 = max(s4, s3+prices[i]);
        }
        return s4;
    }
};
// @lc code=end

