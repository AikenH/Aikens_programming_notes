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
// 通过是通过了，但是时间效率非常不堪，看看下面的基于别人的思路修改过后的结果。
   vector<vector<int>> findContinuousSequence(int target) {
      if(target<=2) return {};
      // init begining; &res;
      int ptr1=1, ptr2=2; // 前后都包含
      int tempsum = 3;
      vector<vector<int>> res;
      vector<int> temp = {1,2};
      int end = (target+1)>>1;
      while(ptr2<=end){
         
         if(tempsum<target){
            temp.push_back(++ptr2);
            tempsum += ptr2;
         }
         else if(tempsum>target){
            tempsum -= temp.front();
            temp.erase(temp.begin());
            ptr1++;
         }
         if(tempsum == target){
            res.emplace_back(temp);
            tempsum -= temp.front();
            temp.erase(temp.begin());
            ptr1++;
         }

      }
      return res;
   }
};

// 同样是双指针的思路：学一下人家的写法
class Solution {
public:
   vector<vector<int>> findContinuousSequence(int target) {
      vector<vector<int>>vec;
      vector<int> res;
      for (int l = 1, r = 2; l < r;){
         int sum = (l + r) * (r - l + 1) / 2;
         if (sum == target) {
               res.clear();
               for (int i = l; i <= r; ++i) {
                  res.emplace_back(i);
               }
               vec.emplace_back(res);
               l++;
         } else if (sum < target) {
               r++;
         } else {
               l++;
         }
      }
      return vec;
   }
};
// 按照别人的思路修改一下我的代码： 速度直接百分百
class Solution {
public:
// 通过是通过了，但是时间效率非常不堪
   vector<vector<int>> findContinuousSequence(int target) {
      if(target<=2) return {};
      // init begining; &res;
      int ptr1=1, ptr2=2; // 前后都包含
      int tempsum = 3;
      vector<vector<int>> res;
      vector<int> temp;
      int end = (target+1)>>1;
      // 最后再一次性加，我这加加减减的八成浪费了很多时间复杂度
      while(ptr2<=end){
         if(tempsum<target){
            ptr2++;
            tempsum += ptr2;
         }
         else if(tempsum>target){
            tempsum -= ptr1;
            ptr1++;
         }
         if(tempsum == target){
            temp.clear();
            for(int i = ptr1; i<=ptr2;i++){
               temp.push_back(i);
            }
            res.emplace_back(temp);
            tempsum -= ptr1;      
            ptr1++;
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