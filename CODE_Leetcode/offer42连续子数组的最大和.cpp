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
// 实际上就是一个动态规划的问题，明确basic case后，然后机型动态转移就行了。
// -----------------------------------------ans--------------------------------
class Solution {
public:
   int maxSubArray(vector<int>& nums) {
      if(nums.empty()) return {};
      int n = nums.size();
      int res = INT_MIN;
      // based cased 包含
      // vector<int> DP(n+1,INT_MIN/2);
      // // 状态转移方程，以当前值为结尾的数组最高是多少，
      // for(int i =1;i<=n;i++){
      //    DP[i] = max(DP[i-1]+nums[i-1], nums[i-1]);
      //    res = max(DP[i], res);
      // }
      // return res;
      // 进行状态空间优化
      int pre = INT_MIN/2; int cur = INT_MIN/2;
      for(int i=0;i<n;i++){
         cur = max(pre+nums[i],nums[i]);
         pre = cur;
         res = max(cur, res);
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