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
   // 我也不知道为什么反过来就对了，可能是越界的问题，这里要好好想想
public:
   int singleNumber(vector<int>& nums) {
      if(nums.empty()) return {};
      // 将每个数字的所有位叠上去，
      vector<int>bitcount (32,0) ;
      
      for(auto num: nums){
         // long int bitmask = 1;
         for(int j=31;j>0;--j){
            bitcount[j] += num&1;
            num>>=1;
         }
      }

      int res = 0;
      for(int i =0; i<32;++i){
         // 先挪出个空位再加上
         res<<=1;
         res += bitcount[i]%3;
      }
      return res;
   }
};
// -----------------------------------------test--------------------------------
// 在这个地方编写测试样例并进行测试；
int main()
{
    std::cin.get();
}