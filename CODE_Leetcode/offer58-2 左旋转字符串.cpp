/*leetcode中算法的测试样板
*/
#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<string>
#include<stack>
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
   string reverseLeftWords(string s, int n) {
      if(s.empty()) return {};
      int n2 = s.size();
      helpreverse(s,0,n2-1); // 整体反转，然后再把前后各自反转就行了把
      helpreverse(s,0,n2-n-1);
      helpreverse(s,n2-n,n2-1);
      return s;
   }
   void helpreverse(string& s, int start, int end){
      // 将整个字符串翻转；为了后续使用，添加index来进行判断,这个进行了一个构造。
      // int n = s.size();
      int l = start, r = end;
      while(l<r){
         swap(s[l],s[r]);
         l++;r--;
      }
      // cout<<s<<endl;
      // return s;
   } 
};
// -----------------------------------------test--------------------------------
// 在这个地方编写测试样例并进行测试；
int main()
{
    std::cin.get();
}