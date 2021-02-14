/*leetcode中算法的测试样板
*/
#include<iostream>
#include<functional>
#include<algorithm>
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

class MedianFinder {
private:
   vector<int> maxl;
   vector<int> minr;
public:
    /** initialize your data structure here. */
   MedianFinder() {
      
   }
   
   void addNum(int num) {
      // 用位运算来判断偶数,偶数放右边，奇数放左边
      // &的优先级比==要低
      if(((maxl.size() + minr.size())&1) == 0){
         /* 当偶数的时候，先排入最大值的堆，然后从最大值的堆中弹出，
         放到右侧即可省去对比的过程 */
         if(maxl.size() >0 && num<maxl[0]){
            maxl.push_back(num);
            // 这里是不是应该用greater，将最大值排到顶才对,
            // 建好堆以后，将其中的最大值弹出
            push_heap(maxl.begin(),maxl.end(),less<int>());
            num = maxl[0];
            // pop_heap将根据规则需要弹出的最大或者最小值移到数组末尾
            pop_heap(maxl.begin(),maxl.end(),less<int>());
            maxl.pop_back();
         }
         minr.push_back(num);
         push_heap(minr.begin(),minr.end(),greater<int>());
      }else{
         // 在这种情况下如果还是归属于最小值堆的话，数据量就会产生不均衡的情况。
         if(minr.size()>0 && num>minr[0]){
            minr.push_back(num);
            push_heap(minr.begin(),minr.end(),greater<int>());
            num = minr[0];
            pop_heap(minr.begin(),minr.end(),greater<int>());
            minr.pop_back();
         }
         maxl.push_back(num);
         push_heap(maxl.begin(),maxl.end(),less<int>());
      }
   }
   
   double findMedian() {
      int fsize = maxl.size()+minr.size();
      if(fsize == 0)
      // 这里exception的文本表达不知道为啥不行 
         throw 1;
      if(fsize&1 == 1) return minr[0];
      else
         return (double)(minr[0] + maxl[0])/2.0f;
   }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// -----------------------------------------test--------------------------------
// 在这个地方编写测试样例并进行测试；
int main()
{
    std::cin.get();
}