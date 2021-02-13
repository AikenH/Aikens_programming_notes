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
// 实际上划分标准就是，根据大小关系来划分左子树和右子树，然后不断递归下去。
// 对于这问题重要的是base case，而based case应该就是前面的都比中间的大，后面的比中间的小吧？
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        if (postorder.empty()) return true;
        int n = postorder.size();
        return helpVerify(postorder, 0, n);
    }
    bool helpVerify(vector<int>& postorder, int begin, int end) {
        //int n = postorder.size();
        // 这个基本情况的分析是比较重要的，不能忽略掉这个。
        if (end <= begin + 1) return true;
        int val = postorder[end - 1];
        int ind = -1;
        for (int i = end - 2; i >= begin; i--) {
            if (postorder[i] < val) {
                ind = i; break;
            }
        }
        for (int i = begin; i < ind; i++) {
            if (postorder[i] >= val) return false;
        }
        //这里的begin很容易写错成0，一定要注意到底是咋回事
        if (ind < 0) return helpVerify(postorder, begin, end - 1);
        return helpVerify(postorder, begin, ind) && helpVerify(postorder, ind + 1, end - 1);
    }
    
};
// -----------------------------------------test--------------------------------
// 在这个地方编写测试样例并进行测试；
int main()
{
    std::cin.get();
}