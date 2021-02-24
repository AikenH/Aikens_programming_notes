/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

// @lc code=start
#include<vector>
#include<unordered_map>
#include<stack>

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        unordered_map<int,int>orderh; // 这个没有长度初始化这种说法的
        stack<int> temps;
        vector<int> res; // 只初始化长度的话，会初始化为0；
        temps.push(nums2[0]);
        // 当遇到比原本的大的时候，我们就直接弹出，直到里面的都比他大
        for(int i =1; i<n; i++){
            while(!temps.empty() && nums2[i]>temps.top()){
                orderh[temps.top()] = nums2[i];
                temps.pop();
            }
            temps.push(nums2[i]);
        }
        // 对于剩下来的哪些元素，就赋值为-1
        while(!temps.empty()){
            orderh[temps.top()] = -1;
            temps.pop();
        }
        // 添加进最终的结果。
        for(int num: nums1){
            res.push_back(orderh[num]);
        }
        return res;

    }
};
// @lc code=end

