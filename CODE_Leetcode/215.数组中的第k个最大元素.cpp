/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
#include<queue>
#include<algorithm>
#include<functional>
#include<random>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if(nums.empty()||nums.size()<k) return {};
        // 首先打乱数组避免极端情况产生
        random_shuffle(nums.begin(),nums.end());
        // 使用二分查找的方法来找到真实的坐标
        int n = nums.size();
        int lo = 0; int hi = n-1;
        int resindex = n-k;
        while(lo<=hi){
            int p = partition(nums,lo, hi);
            if(p>resindex){
                hi = p-1;
            }else if(p<resindex){
                lo = p+1;
            }else{
                return nums[p];
            }
        }
        return -1;
        
    }
    int partition(vector<int>& nums, int lo, int hi){
        // 快排的划分,初始化为lo
        if(lo==hi) return lo;
        int i = lo; int j = hi+1;
        int privot = nums[lo];
        while(true){
            while(nums[++i]<privot){
                if(i>=hi) break;
            }
            while(nums[--j]>privot){
                if(j<=lo) break;
            }
            if(i>=j) break; 
            swap(nums[i],nums[j]);
        }
        swap(nums[lo],nums[j]);
        return j;
    }
};
// @lc code=end

