/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        // 我原本的想法是去遍历，然后能够通过从后往前的方式，减少一些计算量
        // 但是实际上，双指针的办法，从两端先移动较短的那个，是一个更理想的方法
        // 因为在当前边界中，最小的这个作为断点的最大情况已经考虑了，不可能又更优解
        // 所以我们可以直接抛弃这个边界
        int l = 0, r = height.size()-1;
        int res = 0;
            while(l<r){
            if(height[l]<height[r]){
                // int area = height[l]* (r-l)
                res = max(res,height[l]* (r-l));
                ++l;
            }
            else{
                // int area = height[l]* (r-l)
                res = max(res,height[r]*(r-l));
                --r;
            }
            // 相等的情况下，我们化了一下，实际上是不会收到当前值的影响的
            
        }
        return res;

    }
};
// @lc code=end

