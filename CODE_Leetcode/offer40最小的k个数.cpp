/*leetcode中算法的测试样板
*/
#include<iostream>
#include<algorithm>
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
   vector<int> getLeastNumbers(vector<int>& arr, int k) {
      int n = arr.size();
      vector<int> final;
      if(n < k) return {};
      // TODO：补充快排的算法和方法，看一下网友的答案来写可能回快一点。
      // 使用size为k的红黑树或者最大堆去实现<type 比较函数 size>
      // multiset 允许重复 set去除重复元素的情况，然后从迭代器按*取值的方式要知道
      // 还有就是erase通过迭代器来erase的。
      multiset<int,greater<int>> res;
      for(int i = 0;i<n;i++){
         if(res.size()<k) res.insert(arr[i]);
         else{
            auto it = res.begin();
            if(*it>arr[i]){
               res.erase(it);
               res.insert(arr[i]);
            }
         }
      }
      for(auto num: res){
         final.emplace_back(num);
      }
      return final;
   }
};
// -----------------------------------------test--------------------------------
// 在这个地方编写测试样例并进行测试；
int main()
{
    std::cin.get();
}