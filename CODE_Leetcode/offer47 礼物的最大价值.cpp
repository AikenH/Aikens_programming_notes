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
/* 很显然的这题的解决思路就是二维的动态规划问题 ，动态规划问题就是通过前后项之间的依存关系，来建立迭代
的过程*/
// -----------------------------------------ans--------------------------------
class Solution {
public:
   int maxValue(vector<vector<int>>& grid) {
      if(grid.empty()) return -1;
      int m = grid.size(); int n = grid[0].size();
      vector<vector<int>> DP(m+1,vector<int>(n+1,0));
      for(int i =1;i<=m;i++){
         for(int j=1;j<=n;j++ ){
            DP[i][j] = max(DP[i-1][j],DP[i][j-1])+grid[i-1][j-1];
         }
      }
      return DP[m][n];
   }
};
// 同样很显然这样的方法还能进行空间上的优化，编程一维压缩,完美
class Solution {
public:
   int maxValue(vector<vector<int>>& grid) {
      if(grid.empty()) return -1;
      int m = grid.size(); int n = grid[0].size();
      vector<int> DP(n+1,0);
      for(int i =1;i<=m;i++){
         for(int j=1;j<=n;j++ ){
            DP[j] = max(DP[j],DP[j-1])+grid[i-1][j-1];
         }
      }
      return DP[n];
   }
};
// -----------------------------------------test--------------------------------
// 在这个地方编写测试样例并进行测试；
int main()
{
    std::cin.get();
}