/*leetcode中算法的测试样板
*/
#include<iostream>
#include<vector>
#include<unordered_map>
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
//没什么好说的，典型的BFS的题目
class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        //这题实际上就是用广度有限搜索把？
        if (!root) return {};
        queue<TreeNode*> que;
        vector<int> res;
        que.emplace(root);
        //res.emplace_back(root->val);
        while (!que.empty()) {
            TreeNode* temp = que.front();
            res.push_back(temp->val);
            que.pop();
            if (temp->left) que.emplace(temp->left);
            if (temp->right) que.emplace(temp->right);
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