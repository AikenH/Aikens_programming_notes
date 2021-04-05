/*leetcode中算法的测试样板
*/
#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<list>
#include<string>
#include<stack>
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
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //这一题实际上实现的是一个双向的队列的问题，和单调的栈模板实际上是类似的，但是多了个index的判断
        if (nums.empty() || nums.size() < k) return {};

        int n = nums.size();
        //使用一个vectore来存放最终的结果，在使用一个deque来双向的进行遍历，单调的存放从大到小的值
        vector<int> res;
        deque<int> sQue; // 注意deque到底应该怎么定义

        //sQue.push_back(nums[0]);
        for (int i = 0; i < n; i++) {
            //由于最后一个元素操作，所以我们先进行元素存放，在进行判断
            //弹出多余元素
            if (i - sQue.front() == k) sQue.pop_front();
            //弹出小于当前值的值
            while (!sQue.empty() && nums[sQue.back()] < nums[i]) {
                sQue.pop_back();
            }
            // 留下当前的较大值，并存入相应的index
            sQue.push_back(i);
            // 当index>=k的时候就开始进行结果的记录,注意这里不再是index，这里是相应的值
            if (i >= k - 1) {
                res.push_back(nums[sQue.front()]);
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