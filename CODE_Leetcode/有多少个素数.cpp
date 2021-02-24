/*leetcode中算法的测试样板
*/
#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<list>
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
// 返回区间 [2, n) 中有几个素数 
int countPrimes(int n)

// 比如 countPrimes(10) 返回 4
// 因为 2,3,5,7 是素数
// -----------------------------------------ans--------------------------------
Clsd Solution {

public:
   int countPrimes(int n){
      if(n<=2) return 0;
      vector<bool> canwe(n,true);
      int res =0;
      for(int i =2;i*i<n;i++){
         for(int j=i*i;j<n;j+=i){
            canwe[j]= false;
         }
      } 
      for(int i=2;i<canwe.size();i++){
         if(canwe[i]){
            res++;
         }
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