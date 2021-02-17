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
   int search(vector<int>& nums, int target) {
      if(nums.empty()) return 0;
      // 使用二分查找查找首和尾
      int start = binaryfind(nums,target,true);
      int end = binaryfind(nums,target,false);
    //   cout<< start<< "  "<< end<< ' ';
      if(start==-1 && end ==-1) return 0;
      return end-start+1;
   }
   int binaryfind(vector<int>& nums, int target, bool flag){
      int n = nums.size();
      int l=0,r=n-1;
      if(flag){
         while(l<=r){
            int mid = (l+r)>>1;
            if(nums[mid]<target){
               l = mid+1;
            }
            if(nums[mid]>target){
               r = mid-1;
            }
            // 下面这个是二分的特殊情况而已
            if(nums[mid] == target){
               if(mid==0) return mid;
               if(nums[mid-1] == target){
                  r = mid-1;
               }
               if(nums[mid-1] != target){
                  return mid;
               }
            }
         }
      }else{
         // 实际上下面这部分是赋值的无效代码，没什么区别。修改了下搜索方向而已
         while(l<=r){
            int mid = (l+r)>>1;
            if(nums[mid]<target){
               l = mid+1;
            }
            if(nums[mid]>target){
               r = mid-1;
            }
            if(nums[mid] == target){
               if(mid==n-1) return mid;
               if(nums[mid+1] == target){
                  l = mid+1;
               }
               if(nums[mid+1] != target){
                  return mid;
               }
            }
         }
      }
      return -1;
   }
};
// -----------------------------------------test--------------------------------
// 在这个地方编写测试样例并进行测试；
int main()
{
    std::cin.get();
}