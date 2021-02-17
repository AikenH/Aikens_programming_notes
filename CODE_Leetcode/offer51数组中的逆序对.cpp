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
// 官方题解
class Solution {
public:
    int mergeSort(vector<int>& nums, vector<int>& tmp, int l, int r) {
        if (l >= r) {
            return 0;
        }

        int mid = (l + r) / 2;
        int inv_count = mergeSort(nums, tmp, l, mid) + mergeSort(nums, tmp, mid + 1, r);
        int i = l, j = mid + 1, pos = l;
        while (i <= mid && j <= r) {
            if (nums[i] <= nums[j]) {
                tmp[pos] = nums[i];
                ++i;
                inv_count += (j - (mid + 1));
            }
            else {
                tmp[pos] = nums[j];
                ++j;
            }
            ++pos;
        }
        for (int k = i; k <= mid; ++k) {
            tmp[pos++] = nums[k];
            inv_count += (j - (mid + 1));
        }
        for (int k = j; k <= r; ++k) {
            tmp[pos++] = nums[k];
        }
        copy(tmp.begin() + l, tmp.begin() + r + 1, nums.begin() + l);
        return inv_count;
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> tmp(n);
        return mergeSort(nums, tmp, 0, n - 1);
    }
};

作者：LeetCode-Solution

// 利用归并排序的原理去做的更好的切分实现如下：
// 这里实现的应该就是书上的思路，但是这个接待不知道为什么还是超过了时间，和官方题解的区别也就在于搜索的方向不一致
// 我们是从后往前，他是从前往后，讲道理不应该是超出时间的，既然这个那个99
class Solution {
public:
   int reversePairs(vector<int>& nums){
      if (nums.empty()) return 0;
      int n = nums.size();
      vector<int>copyNums(n);
      for (int i=0;i<n;i++){
         copyNums[i] = nums[i];
      }
      int res = helpcount(nums,copyNums,0,n-1);
      return res;

   }
   int helpcount(vector<int>& nums, vector<int>& copyNums, int start, int end){
      // return 当前集合中含有的逆序个数，所以除了每次的left和right还要将两部分的差别给整合起来
      //base cases: 
      if(start>=end) {
         copyNums[start] = nums[start];
         return 0;
      }
      // postorder: start指向第一个，end指向最后一个，所以中位数应该是直接/2 
      // 定义为双包含的架构，手动写出offset
      int lens = (end - start) >>1;
      int right = helpcount(nums, copyNums, start, start+lens);
      int left = helpcount(nums,copyNums,start+lens+1, end);

      // main: merge ,sort andcount，use "two pointers" to help
      int pl = start+lens; int pr = end; int indexc = end;
      int count = 0;
      while(pl>=start && pr>start+lens){
         if(nums[pr]<nums[pl]){
            // 所有值满足逆序对
            count += (pr - start - lens);
            copyNums[indexc--] = nums[pl--];
         }
         else{
            copyNums[indexc--] = nums[pr--];
         }
      }
      // 命名已经排序号的数组是copynums，为什么我们对比的时候使用的是nums
      for(;pl>=start;pl--) copyNums[indexc--] = nums[pl];
      for(;pr>start+lens;pr--) copyNums[indexc--] = nums[pr];

      copy(copyNums.begin(),copyNums.end(),nums.begin());
      cout<<left+right+count<<" ";
      return left+right+count;
   }
};
// 基本的解法如下，但是回超出时间限制。
// class Solution {
// public:
//    int reversePairs(vector<int>& nums) {
//       if(nums.empty()) return 0;
//       int n = nums.size();
//       vector<int> DP(n,0);
//       DP[0] = 0; 
//       int res = 0;
//       for(int i = 1;i<n;i++){
//          for(int j=i-1; j>=0;j--){
//             if(nums[i]<nums[j]){
//                DP[i] ++;
               
//             }
//          }
//          res += DP[i];
//       }
//       return res;
//    }
// };
// -----------------------------------------test--------------------------------
// 在这个地方编写测试样例并进行测试；
int main()
{
    std::cin.get();
}