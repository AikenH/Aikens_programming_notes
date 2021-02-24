/*
 * @lc app=leetcode.cn id=1109 lang=cpp
 *
 * [1109] 航班预订统计
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        // 初始化结果数组
        vector<int> res(n,0);
        if(bookings.empty()) return res;
        // 构建差分数组,初始就全是0，没问题的
        vector<int> diff(n,0);
        
        // 差分求解
        for(auto book: bookings){
            int i = book[0]-1;
            int j = book[1]-1;
            int val = book[2];
            diff[i]+= val;
            if(j+1<n) diff[j+1]-=val;
            
        }
       
        // 数组还原
        res[0] = diff[0];
        for(int i =1;i<n;i++){
            // cout<<diff[i]<<" ";
            res[i] = diff[i]+res[i-1];
        }
        return res;
    }
};
// @lc code=end

