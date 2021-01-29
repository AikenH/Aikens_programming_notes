/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
// #include<vector>
// using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // 基于二分查找和贪心的算法
        vector<int>DpT(nums.size()+1,0); // 这里好像没考虑到负数的情况吧,便于比较和加入所以+1
        int lens = 1;
        DpT[lens] = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>DpT[lens]){
                DpT[++lens] = nums[i];
            }
            else{
                // 二分查找大型现场。
                int left = 1, cur=0, right = lens;
                while(left <= right){
                    int mid =(left+right)>>1;
                    if(nums[i]>DpT[mid]){
                        // 这里为什么要+1，避免重复搜索同时做种错开吗？
                        left = mid+1;
                        cur = mid;
                    }
                    else{
                        right = mid-1;
                    }
                }
                DpT[cur+1] = nums[i];
            }
        }
        return lens;
    }
};
// @lc code=end

// 首先阐述一下我拙劣的观点：
/*
1. 首先找到长长度为一的所有子序列，然后从这个子序列的尾巴出发，找到后续的长度+1的子序列
2. 覆盖，清楚，（O(2N)的空间） （O（n^3））太差了，正常动态规划应该怎么去做。

为什么不能用以每个结尾的子串中的最长子序列来做动态规划
因为最大值不可控，而且主要是这个玩意没办法重复利用。还是需要从重复寻找子序列。


*/