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
   int findNthDigit(int n) {
      /* 很容易分析得到，1位数字有10个 2位数字有90个 也就是180个index，3位数有 （1000- 100）*3 
      所以这题递归的去减*/
      int biteloc = 1; long int count = 10;
      if(n<10) return n;
      int pre=0;
      // 递归的减少，通过前一位pre找到，现在是第几位
      while(n>=count){
         biteloc ++;
         pre = count;
         count += (pow(10,biteloc)- pow(10,biteloc-1))*biteloc;
      }
      // help 是第几个数字 help2 数字中的第几位，从0开始
      int help = (n-pre) / biteloc;
      int help2 = (n-pre) % biteloc;
      // 通过help找到相应的val 然后由于是前序的，就通过string 输出该位
      help = help + pow(10,biteloc-1);

      string restring = to_string(help);
      return (int)(restring[help2] - '0');
   }
};
// -----------------------------------------test--------------------------------
// 在这个地方编写测试样例并进行测试；
int main()
{
    std::cin.get();
}