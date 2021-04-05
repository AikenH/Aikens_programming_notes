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

class Solution {
public:
   vector<int> getLeastNumbers(vector<int>& arr, int k){
       if(k<=0) return {};
      // 使用优先队列来编写，熟悉一下优先队列的语法
      int n = arr.size();
      // 这样的话就是大顶堆
      priority_queue<int,vector<int>,less<int>> leastK;
      // 当size《k的时候就直接insert，当size》k的时候就进行top的弹出
      for(auto num: arr){
         if(leastK.size()<k) leastK.push(num);
         else{
            if(num < leastK.top()){
               leastK.pop();
               leastK.emplace(num);
            }
         }
      }
      // 遍历完以后最终的结果就是k个数字
      vector<int> finalres;
      while(!leastK.empty()){
         // 非空的时候就不断的弹出
         int temp = leastK.top();
         finalres.emplace_back(temp);
         leastK.pop();
      }
      return finalres;
   }
};

class Solution{
   void quickSort(vector<int>& arr, int k, int leftP, int rightP){
      // 直接进行一个快的排
      int splitPoint = leftP; int left = leftP; int right = rightP;
      while(left<right){
         while(left<right && arr[right]>= arr[splitPoint]) right--;
         while(left<right && arr[left]<= arr[splitPoint]) left ++;
         if(left<right) swap(arr[left], arr[right];)
      }
      swap(arr[right], arr[splitPoint]);
      if(right == k-1) return;
      else if(right>k) quickSort(arr, k , splitPoint, right);
      else if(right<k) quicksort(arr,k,right,rightP);
      return;

   }
   vector<int> getLeastNumbers(vector<int>& arr, int k){
      // 首先当我们实现了快排的方式的时候，这种情况下已经是至少已经找到了k个数，但是之间的顺序可能没拍好
      if(k<=0) return {};
      int n = arr.size();
      quickSort(arr,k,0,n-1);
      vector<int> res;
      for(int i = 0; i < k; i++){
         res.push_back(arr[i]);
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