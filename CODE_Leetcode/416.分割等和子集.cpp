/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    // 首先进行求和，然后将sum/2作为背包的容量，那么实际上就是一个背包问题
    // 只要对最终的情况进行判断是否为相等就行。
    // FIXME：但是这一题的最终重要的问题在于模型压缩，我们如何实现状态转移中的压缩。
    // 还有运算时间的优化，这题可以换成bool来做。思考一下。
    // 用bool的方式去做实际上就是一个状态的集成，所有的j=0都是true。,然后逐步进行状态的转移和传递即可
    bool canPartition(vector<int>& nums) 
    {
        // 求和
        int sum = 0;
        for (int& num: nums) sum += num;
        // 背包问题求解
        if(sum%2 != 0) return false;
        sum = sum/2;
        vector<bool> bapack (sum+1,false);
        bapack[0] = true;
        // i 对第i个物体进行判断 j 当前已装入的重量总数；好好分析
        for (int i = 1;i<= nums.size();i++){
            for(int j = sum;j>=0;j--){
                // 很明显需要保存的就是上一轮的结果 i-1的情况，别的没啥好说的了
                if (j<nums[i-1]);
                else{ // 这个else 不能省略
                    // 只要其中有一个是true就是true，很直接的说法
                    bapack[j] = bapack[j] || bapack[j-nums[i-1]]; // TODO:需要注意这里不要覆盖了更新，所以，要反着来
                }
            }
        }
        return bapack[sum];

    }
};
// @lc code=end

