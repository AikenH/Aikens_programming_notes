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
   int maxd = 0;
public:
   int maxDepth(TreeNode* root) {
      if(!root) return 0;
      helpmax(root,0);
      return maxd;
   }
   void helpmax(TreeNode* root, int depth){
      if(!root){
         maxd = max(maxd, depth);
         return;
      }
      helpmax(root->left,depth+1);
      helpmax(root->right,depth+1);
   }
};
// -----------------------------------------test--------------------------------
// 在这个地方编写测试样例并进行测试；
int main()
{
    std::cin.get();
}