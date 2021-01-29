/*leetcode中算法的测试样板
*/
#include<vector>
#include<unordered_map>
// -----------------------------------------question--------------------------
//* Definition for a binary tree node.
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
private:
    int ans = INT_MIN;
public:
     // 好像不需要自己写std
    int maxPathSum(TreeNode* root) {
        helpSum(root);
        return ans;
    }
    int helpSum(TreeNode* root)
    {
        if (root == nullptr)
            return 0;
        // 考虑negative的情况；用0来判断是否要输入
        int rightG = max(helpSum(root->right), 0);
        int leftG = max(helpSum(root->left), 0);
        // 不经过该节点的情况已经在子节点的地方输出了，不需要我自己画蛇添足的在这里进行政府的判断；
        int temp = root->val + rightG + leftG;
        ans = max(temp,ans);
        // 最终都是复数的情况？可能还要考虑temp和val哪个更小的问题
        return max(rightG,leftG) + root->val;
    }
};
// -----------------------------------------ans--------------------------------

// -----------------------------------------test--------------------------------
// 在这个地方编写测试样例并进行测试；
int main()
{
    std::cin.get();
}