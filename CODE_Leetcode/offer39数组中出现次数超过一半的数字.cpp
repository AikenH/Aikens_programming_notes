/*leetcode中算法的测试样板
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<string>
#include<queue>
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
private:
   unordered_map<int,unsigned int> temp;
public:
   int majorityElement(vector<int>& nums) {
      int n = nums.size();
      for(auto num:nums){
         if(temp.find(num) == temp.end()){
            temp[num] = 0;
         } else{
            temp[num] ++;
         }
      }
      for(auto it = temp.begin();it!=temp.end() ;it++){
         if(it->second >= (n>>1)){
            return it->first;
         }
      }
      // 大部分的空值应该就是通过这个{}来确定的。
      return {};
   }
};
// -----------------------------------------test--------------------------------
// 在这个地方编写测试样例并进行测试；
int main()
{
    std::cin.get();
}