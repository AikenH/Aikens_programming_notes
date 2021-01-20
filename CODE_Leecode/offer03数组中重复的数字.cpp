
#include<vector>
#include<unordered_map>
// -----------------------------------------question--------------------------------

找出数组中重复的数字。
在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，
也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。

示例 1：

输入：
[2, 3, 1, 0, 2, 5, 3]
输出：2 或 3 

// -----------------------------------------ans--------------------------------
// -----------------------------------------Solution 1 HASH but not the bestone--------------------------------
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        // 如果构建hash表的话，可能就需要一个新的存储空间，所以这里是否是使用书上提到的那种方法回更好的呢，但是复杂度是怎么分析的来着。
        unordered_map<int> hashmap;
        for(int& num: nums)
        {
            auto it = hashmap.find(num);
            if (it != hashmap.end())
            {
                return num;
            }
            hashmap[num] = 1; 
            // 无论是啥无所谓了，但是问题是：unordered_map 能不能建立只有key的hash？查一下  好像是没有的
            // 第二点，这是不是还不如用来建立一个新的vector或者数组呢？ 
            // 分析一下unorder的size和vector的。 
        }
        
        return {};
            
    }
};
// -----------------------------------------Solution2   --------------------------------
// 实际上就是一个不需要额外存储空间的hash方法，也没什么特别的。
// 就是在原数组上进行修改值，用hash的方式进行排列。
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++)
        {
            while (i != nums[i])
            {
                if (nums[i] >= nums.size())
                    return {};
                if (nums[nums[i]] == nums[i])
                    return nums[i];
                else
                {
                    int temp = nums[nums[i]];
                    nums[nums[i]] = nums[i];
                    nums[i] = temp;
                }
                
            }
        }
        return {};
    }
};
// -----------------------------------------Solution3   --------------------------------
// 是否有办法实现就是，不需要内存空间，也不修改原本数组的方法来实现这样的duplicate搜索
// 使用一个参数来做匹配把，看<n的有多少个,进行2分查照，对数组不做切分，但是对值做切分（也就是对值进行2分查找的意思）
// 每次搜索整个数组，搜索logn次，所以时间复杂度 nlogn；
// 这个方法还是存在一定的缺陷，就是比如划分的时候13，14 里面没有13，只有两个14，这种情况算法count是不是会出现错误呢。所以还是有待商榷的。
// 可能还要加入回滚判断的步骤。就有点离谱了。后续再分析吧，先往前。
class Solution
{
public:
    int findRepeatNumber(vector<int>& nums)
    {
        int start = 0, end = nums.size();
        while (start <= end)
        {
            int mid = ((end - start) >> 1) + start;
            int count = countnum(start, mid, nums);
            std::cout << start << "//" << mid << "//" << end << "count" << count << std::endl;
            if (end == start)
            {
                if (count > 1)
                    return start; //对单值进行计数，>1了的话就是重复了啊，这还有啥好说的；
                else
                    break;
            }
            if (count > (mid - start + 1))
                end = mid;
            else
                start = mid + 1; // 因为中位数在后面已经取到过了，所以就只要计算后面一位开始；
        }
        return -1;

    }
    int countnum(int middle, int end, vector<int>& nums)
    {
        int count = 0;
        if (nums.empty())
        {
            std::cout << "it's empty" << std::endl;
            return 0;
        }

        for (int& num : nums)
        {
            if (num >= middle && num <= end)
            {
                ++count;
            }
        }
        return count;
    }
};

// -----------------------------------------test--------------------------------
// 在这个地方编写测试样例；
int main()
{
    // nullptr,{1,2,3,4},{1,1,1}
    
    std::cin.get();
}