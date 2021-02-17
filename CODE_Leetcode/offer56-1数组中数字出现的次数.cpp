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
// 思路上和我写的方法是完全一样的，但是不知道我的方法到底哪里错了
class Solution {
public:
   vector<int> singleNumbers(vector<int>& nums) {
      int ret = 0;
      for (int n : nums)
         ret ^= n;
      int div = 1;
      while ((div & ret) == 0) // 这里是单等号，实际上是因为字体的原因看起来想双灯好
         div <<= 1;
      int a = 0, b = 0;
      // 这个按位操作的还是不够熟悉，
      for (int n : nums)
      // 根据该位是不是0划分一下，两种类型开始与。
         if (div & n)
               a ^= n;
         else
               b ^= n;
      return vector<int>{a, b};
   }
};
// -----------------------------------------test--------------------------------
// 在这个地方编写测试样例并进行测试；
int main()
{
    std::cin.get();
}