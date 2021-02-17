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
private:
   vector<int> res;
public:
   int kthLargest(TreeNode* root, int k) {
      if(!root) return {};
      midtraver(root);
      int n = res.size();
      return res[n-k];
      
   }
   void midtraver(TreeNode* root){
      if(!root) return;
      midtraver(root->left);
      res.push_back(root->val);
      midtraver(root->right);
      return;
   }
};
// -----------------------------------------test--------------------------------
// 在这个地方编写测试样例并进行测试；
int main()
{
    std::cin.get();
}