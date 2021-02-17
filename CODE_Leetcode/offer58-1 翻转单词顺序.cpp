/*leetcode中算法的测试样板
*/
#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<stack>
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
/* TODO: 这里用这种反转的写法是因为书上这么些的，这种方法对后面的空格的去除是真的麻烦。
要是我的话，我的想法是从后往前遍历，然后记住单词的框架
将单词逐个添入vector，然后最后拼起来这种，或者直接加到string中 */

class Solution {
public:
   string reverseWords(string s) {
      if(s.empty()) return {};
      int n = s.size();
      helpreverse(s,0,n-1);
      int start = 0; int end = 0;
      for(int i=0;i<n;i++){
         if(s[i] == ' '){
            // NOTE:这里要注意这个end和start该怎么设置
            end = i-1; helpreverse(s,start,end);
            start = i+1;
         }
      }
      // 以及当数组结尾的时候还要再翻转一次
      helpreverse(s,start,n-1);
      
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
// 正统我的想法的实现：
class Solution {
public:
   string reverseWords(string s) {
      if(s.empty()) return{};
      int len = s.length();
      // if (len == 0) {
      //    return "";
      // }
      int j = len - 1;
      string res = "";
      while (j >= 0) {
         if (s[j] == ' ') {
               // 当 s[j] 是空格时，j 不断左移
               j--;
               continue;
         }
         while (j >= 0 && s[j] != ' ') {
               // 注意 while 里必须用 && 短路求值，且 j >= 0 要放前面
               // 不然如果 j 变成 -1，那么计算 s[j] 会发生溢出错误！
               j--;
         }
         int pos = j; // 用 pos 保存 j 当前的位置
         j++; // j 现在指向的是一个空格，需要右移一位才能指向一个单词的开头
         while (s[j] != ' ' && j < len) {
               // 向 res 中添加单词
               res += s[j];
               j++;
         }
         j = pos; // j 回到新添加的单词的最左端再往左一个空格处
         res += ' '; // 单词添加完毕后需要加上一个空格
      }
      if (!res.empty() && res[res.length() - 1] == ' ') {
         // 删除 res 最后一位的多余空格
         // TODO:rease的第二个用法
         res.erase(res.length() - 1, 1);
      }

      return res;
   }
};

// 邪道：istringstream的方法，实际上思路和我那个是一样的，但是就是更简洁的表达了。
class Solution {
public:
   string reverseWords(string s) {
      stack<string> stk;
      string res,str;
      istringstream ss(s);
      while (ss >> str) stk.push(str), stk.push(" ");
      if (!stk.empty()) stk.pop();
      while (!stk.empty()) res += stk.top(), stk.pop();
      return res;
   }
};

class Solution {
public:
   string reverseWords(string s) {
      istringstream ss(s);
      string res, str;
      while(ss >> str)
         res = str + ' ' + res; //妙啊
      return res.substr(0, res.size() - 1);
   }
};

// -----------------------------------------test--------------------------------
// 在这个地方编写测试样例并进行测试；
int main()
{
    std::cin.get();
}