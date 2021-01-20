/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
// 遍历的写法纯傻逼，遍历是不可能遍历的,用hash表的方法来进行搜索？
// 这题显然是python更简单
// vector 返回值是两个的情况怎么说？
#include<vector>
#include<unordered_map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int, int> hashmap;
        for (int i = 0; i < nums.size(); i++)
        {
            //std::iterator<int, int> tempvalue = hashmap.find(target - nums[i]);
            auto it = hashmap.find(target - nums[i]); // 这应该是一个迭代器类型↑
            if (it != hashmap.end())
            {
                return { it->second ,i };
            }
            //在原本的hashmap中将现在的元素和index嵌入进去
            hashmap[nums[i]] = i;
            
        }
        return {};
    }
};
// @lc code=end


// unorder_map 实际上是Cpp中对Hash的实现
// unorder_map 的end不是指向最后一个元素的位置而是最后一个元素后面的位置
// find返回一个迭代器（迭代器中的second指的是hash中的valye（也就是实际的key））
// unordered_map find的迭代器使用++来找到该key中的所有地址？
// vector 返回值有两项，就是用两项去初始化一个vector被，本来就是一个项数不确定的动态数组了吧。