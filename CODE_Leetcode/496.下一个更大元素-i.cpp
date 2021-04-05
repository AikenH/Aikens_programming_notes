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
        if (nums2.empty() || nums1.empty() || nums2.size() < nums1.size()) return {};
        int n1 = nums1.size(); int n2 = nums2.size();
        //用一个hashmap存储相应的元素对应的下一个更大的val
        unordered_map<int, int> orderHash;
        stack<int> orderStack;
        orderStack.push(nums2[0]);
        //存放最终结果的向量
        vector<int> res;
        for (int i = 1; i < n2; i++) {
            //栈内存的数据应该从大到小，直到下一个比当前的top还大的到来，我们就开始pop()
            while (!orderStack.empty() && orderStack.top() < nums2[i]) {
                int temp = orderStack.top();
                orderHash[temp] = nums2[i];
                orderStack.pop();
            }
            orderStack.push(nums2[i]);
        }
        //但是如果一直没有比现在大的过来,就标记为-1；
        while (!orderStack.empty()) {
            orderHash[orderStack.top()] = -1;
            orderStack.pop();
        }
        //然后录入结果
        for (int num : nums2) {
            res.emplace_back(orderHash[num]);
        }
        return res;


    }
};
// @lc code=end

