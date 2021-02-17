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
   int missingNumber(vector<int>& nums) {
      // 很直观的二分查找法
      if(nums.empty()) return {};
      int n = nums.size();
      int l=0,r=n-1;
      while(l<=r){
         int mid = (l+r)>>1;
         if(nums[mid]==mid){
            l = mid+1;
         }else{
            r = mid-1;
         }
      }
      return l;
   }
};
// -----------------------------------------test--------------------------------
// 在这个地方编写测试样例并进行测试；
int main()
{
    std::cin.get();
}