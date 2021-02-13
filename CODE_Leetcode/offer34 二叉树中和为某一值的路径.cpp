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
class Solution {
private:
    vector<vector<int>> res;
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (!root ) return {};
        vector<int> temp;
        int now = 0;
        helpPath(root, sum, now, temp);
        return res;
        
    }
    void helpPath(TreeNode* root, int sum, int now, vector<int>& temp) {
        if (!root) return;
        int nval = root->val;
        now += nval;
        
        //由于val可正可负，所以这样的操作就是错误的，因为我们没法知道正确的情况是怎么样的。
        //if (now > sum) {
        //    now -= nval;
        //    return;
        //}

        temp.push_back(nval);

        if (!root->left && !root->right) {
            if (now == sum) res.emplace_back(temp);
        }
        else {
            helpPath(root->left, sum, now, temp);
            helpPath(root->right, sum, now, temp);
        }
        
        temp.pop_back();
        return;
    }
};
// -----------------------------------------test--------------------------------
// 在这个地方编写测试样例并进行测试；
int main()
{
    std::cin.get();
}