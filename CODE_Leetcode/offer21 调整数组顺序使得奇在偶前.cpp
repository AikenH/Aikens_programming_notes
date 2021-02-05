/*leetcode中算法的测试样板
*/
#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<queue>
using namespace std;
// -----------------------------------------question--------------------------

// -----------------------------------------ans--------------------------------
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        // 如果要编写一个通用的模块的话，就是处理一下这个判断条件用一个lambda函数就可以了
        auto judge = [&](int index){return nums[index]%2 == 0;};
        while(l<=r){
            // 右侧是奇数 左侧是偶数的情况
            if(nums[l]%2 == 0 && nums[r]%2 != 0)
            {
                int temp = nums[l];
                nums[l] = nums[r];
                nums[r] = temp;
                l++; r--;
            }
            else{
                if(nums[l]%2 == 1) l++;
                if(nums[r]%2 == 0) r--;
            }
        }
        return nums;
    }
};
// -----------------------------------------test--------------------------------
// 在这个地方编写测试样例并进行测试；
int main()
{
    std::cin.get();
}