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
// 思路1：使用hashset和que来模拟int和index 实际上就是一个滑动窗口的问题，
// 那么参考网友的思路，我们实际上可以根据ascii的128个，来用vector做一个滑动窗口
// 学， 特别聪明了
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int map[128] = {0}, len = 0, start = 0;  //map统计字符在当前子串出现次数,字符的ascii码值小于128
        for(int i = 0; i < s.size(); ++i)    
        {
            ++map[s[i]];
            while(map[s[i]] == 2)   //出现重复
                --map[s[start++]];  //不断滑动右移的同时恢复map中的状态，当map[s[i]]=1时，确定新的start
            len = max(len, i - start + 1);
        }
        return len;
    }
};
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> map(128, -1);         //map记录字符在当前子串上次出现的位置 
        int len = 0, start = 0;            //int map[128] = {-1}会出错;这只让第一个值为-1，其余的还是为0
        for(int i = 0; i < s.size(); i++)
        {
            if(map[s[i]] >= start)      //此时还未进行本轮赋值，如果>start，表示s[i]赋值过，在本段中出现过
                start = map[s[i]] + 1;  //map[s[i]]记录上次出现本字符的位置，+1更新start为新的子串起始位置
            map[s[i]] = i;               
            len = max(len,i - start + 1);
        }
        return len;
        }
};

class Solution {
public:
   int lengthOfLongestSubstring(string s) {
      if(s.empty()) return 0;
      int maxlen = 0; int templen=0; int n = s.size();
      queue<int> que; unordered_set<int> hash;
      for(int i =0;i<n;++i){
         if(hash.find(s[i])==hash.end()){
            hash.insert(s[i]);
            que.emplace(s[i]);
            ++templen;
            
         }else{
            maxlen = max(templen,maxlen);
            while(que.front() != s[i]){
               hash.erase(hash.find(que.front()));
               que.pop();
            }
            que.pop();
            // hash.insert(s[i]);
            que.emplace(s[i]);
            templen = que.size();
         }
      }
      maxlen = max(templen,maxlen);
      return maxlen;
   }
};
// -----------------------------------------test--------------------------------
// 在这个地方编写测试样例并进行测试；
int main()
{
    std::cin.get();
}