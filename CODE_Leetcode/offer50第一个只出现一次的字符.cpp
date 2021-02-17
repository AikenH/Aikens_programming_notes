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
   char firstUniqChar(string s) {
      if(s.empty()) return ' ';
      
      unordered_map<char,int>count;
      for(char c:s){
         ++count[c];
      }
      // unordered_map初始化方式还是要注意啊。
      // 这题实际上还是可以用vector代替的长度就是字符串的长度。
      for(char c:s){
         if(count[c]==1)
            return c;
      }
      return ' ';

   }
};
// -----------------------------------------test--------------------------------
// 在这个地方编写测试样例并进行测试；
int main()
{
    std::cin.get();
}