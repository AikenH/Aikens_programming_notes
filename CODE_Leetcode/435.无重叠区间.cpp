/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */

// @lc code=start
#include<algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.empty()) return 0;
        sort(intervals.begin(),intervals.end(),\
            [](const auto& A,const auto& B){return A[1]<B[1];});
        int eol = intervals[0][1];
        int count = 1;
        for(auto& list : intervals){
            if(list[0]>=eol){
                eol = list[1];
                count++;
            }
        }
        return intervals.size() - count;
    }
};
// @lc code=end

