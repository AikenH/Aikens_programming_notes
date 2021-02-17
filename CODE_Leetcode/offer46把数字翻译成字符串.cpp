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
/* 我认为这题应该可以使用回溯法和动态规划来解决这个问题：
1. 回溯法，就根据1个或者2个，进行分裂穷举，当最终剩下一个或者两个的时候就return就行了。+count,
回溯法的方法，事实证明，要不然就调用Set来做？或者还是使用动态规划的方法好了。
2. 动态规划的方法，很明显能够划分成子问题来做，所以就使用dp的策略去递归，循环。 */
// class Solution {
// private:
//    unordered_set<string> res;
// public:
//    int translateNum(int num) {
//       if(num<0) return 0;
//       string nums = to_string(num);
//       string temp;
//       backtrack(nums,0,temp);
//       return res.size();
//    }
//    void backtrack(string& nums, int start, string& temp){
//       int n =nums.size();
//       if(start>=n) return;
//       if(temp.size()== n) res.insert(temp);
//       // 在这里实际上会遇到两次，比如说3个数字的情况，推进1的时候
//       char cur = nums[start]; 
//       temp = temp+cur;
//       start++;
//       backtrack(nums, start,temp);
//       start--;
//       temp.pop_back();
      
//       if(n-start == 2){
//          char next = nums[start+1];
//          if(cur <='2' || cur == '2' && next<='5'){
            
//             temp = temp+cur+next;
//          }
//       }
//       start+=2;
//       backtrack(nums,start,temp);
//       start -= 2;
//       temp.pop_back();
//       temp.pop_back();
      
//       return;
//    }
// };

// FIXME:重新温习动态规划，然后这一题主要是这个转移方程和初始条件我都没想好。
// 实际上就是和打家劫舍是类似的，要看清楚，下面这个是空间优化前的理解version； 
class Solution {
public:
   int translateNum(int num) {
      string src = to_string(num);
      int n = src.size();
      vector<int> DP(n+1,1);
      DP[0] = 1;
      for(int i =1;i<n;i++){
         // substr的用法 起始点和长度
         auto subc = src.substr(i-1,2);
         if(subc<="25" && subc>="10" ) {
            DP[i+1] = DP[i-1] +DP[i];
            cout<<subc<<" ";
         }
            
         else 
            DP[i+1] = DP[i];
      }
      return DP[n];
   }
};
// 改进ver
class Solution {
public:
   int translateNum(int num) {
      string src = to_string(num);
      int n = src.size();
      int pre1 = 1; int cur = 1; int temp;
      // DP[0] = 1;
      for(int i =1;i<n;i++){
         // substr的用法 起始点和长度
         auto subc = src.substr(i-1,2);
         if(subc<="25" && subc>="10" ) {
            temp = cur;
            cur = pre1 + cur;
            pre1 = temp;
            // cout<<subc<<" ";
         }
         else{
            // 这一部分很容易漏掉，我们还是要滚动着维护。
            pre1 = cur;
         }
      }
      return cur;
   }
};


// -----------------------------------------test--------------------------------
// 在这个地方编写测试样例并进行测试；
int main()
{
    std::cin.get();
}