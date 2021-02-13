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
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        
    }
};
// -----------------------------------------test--------------------------------
// 在这个地方编写测试样例并进行测试；
int main()
{
    std::cin.get();
}