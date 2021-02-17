/*leetcode中算法的测试样板
*/
#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<string>
#include<queue>
#include<set>
using namespace std;

struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//Definition for singly-linked list.
struct ListNode {
   int val;
   ListNode* next;
   ListNode(int x) : val(x), next(NULL) {}
};

// -----------------------------------------question--------------------------

// -----------------------------------------ans--------------------------------
class Solution {
public:
   vector<int> twoSum(vector<int>& nums, int target) {
      unordered_set<int> presave;
      vector<int> res(2,-1);
      for(int num: nums){
         int need = target-num;
         if(presave.find(need)!=presave.end()) {
            res[0] = num; res[1] = need;
            break;
         }else
            presave.insert(num);
      }
      return res;
   }
};
// 简单的双指针遍历的方法，反正只要找到一个就行了
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0, j = nums.size()-1;
        while(i < j)
        {
            if(nums[i] + nums[j] == target)  return {nums[i],nums[j]};
            if(nums[i] + nums[j] > target)  --j;
            if(nums[i] + nums[j] < target)  ++i;
        }
        return {};
    }
};


// -----------------------------------------test--------------------------------
// 在这个地方编写测试样例并进行测试；
int main()
{
    std::cin.get();
}