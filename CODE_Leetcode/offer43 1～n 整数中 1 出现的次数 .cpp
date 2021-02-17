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
   int countDigitOne(int n) {
      /* 实现思路：从最低位往高位迭代，然后每次做出两个判断，也就是当前位是否为1，分为两种情况。(还要考虑当前位为0的情况) */
      if(n<=0) return 0;
      long int highc = 10; long int lowc = 1; 
      int res = 0;
      while(n>=lowc){
         // 通过highc 取余以及和lowc*2对比判断当前位；
         int cur = n%highc;
         // 排除了当前位为0 的情况，当前位位
         if(cur>=lowc){
            if(cur<lowc*2){
               // 考虑到当前位是1的情况
               res += (n/highc * lowc) + (n%lowc+1);
            }else{
               // 当前位大于1的情况
               res += (n/highc + 1)* lowc;
            }
            
         }else{
            res += (n/highc * lowc);
         }
         // 步进
         lowc *= 10; highc *= 10;   
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