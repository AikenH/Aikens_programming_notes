/*
 * @lc app=leetcode.cn id=354 lang=cpp
 *
 * [354] 俄罗斯套娃信封问题
 */

// @lc code=start
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if(envelopes.empty())
            return 0;
        // 使用匿名函数编写排序算法，sort采用的是快排的基本方法
        sort(envelopes.begin(), envelopes.end(),
            [](const vector<int> & A , const vector<int> & B){
                return A[0]<B[0] || (A[0]==B[0] && A[1]>B[1]);
            });
        // 接着使用二分查找结合动态规划来搜索最长递增子序列
        vector<int> dpt (envelopes.size()+1, 0);
        // HYPER 
        int len = 1;
        dpt[len] = envelopes[0][1];
        for (int i = 1;i<envelopes.size();i++)
        {
            // 如果比原本的大，就直接放到后面去，如果没比前面的大，就放到第一个比他大的下面，修改他的值
            // 但是如果比第一个值还小的话，就会被放到最前面（第一个好像这样是搜不到0的）去，最后多长的话，是不是就说不准了？
            if(envelopes[i][1]>dpt[len]){
                len = len + 1;
                dpt[len] = envelopes[i][1];

            }
            else{
                //TODO:lower_boundry的使用
                // FIXME:不知道这个二分查找的问题在哪，非常疑惑 change的位置放错了
                int l = 1, r = len, cur = 0;
                while(l<=r){
                    int mid = (l+r)>>1;
                    if (envelopes[i][1]>dpt[mid]){
                        l = mid+1;
                        cur = mid;  // 最终就会是小于的最后一个
                    }
                    else{
                        r = mid ;
                    }
                    

                }

                dpt[cur+1] = envelopes[i][1];
            }
        }
        return len;
        
    }
};
// @lc code=end

