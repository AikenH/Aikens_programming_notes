/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */

// @lc code=start
// 实际上也是重叠区间的问题，但是就是反过来了，如果是重叠了，就不需要+1，如果没有重叠就需要+1
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.empty()) return 0;
        sort(points.begin(),points.end(),\
            [](const auto& A,const auto& B){return A[1]<B[1];});
        int eol = points[0][1];
        int count = 1;
        for(auto& list : points){
            if(list[0]>eol){
                eol = list[1];
                count++;
            }
        }
        return count;
    }
};
// @lc code=end

