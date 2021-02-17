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
public:
   int nthUglyNumber(int n) {
      if(n <= 0) return -1;
      vector<int> uglyNums = {1,2,3,4,5}; //存放已求得丑数
      // 指向下一个开始*的数字的index
      int count = 5;
      vector<int> indn(3,1);
      vector<int> times(3,2); times = {2,3,5};
      indn[0] = 2;
      // 当size不足的时候接着循环就是了
      while(count < n){
         // FIXME:这里同时还需要排除重复，手动排除还是试着使用unorder_map在保留序号的同时处理；
         int res = 0; int tempmin = uglyNums[indn[0]]* 2;
         for(int i =1; i<3;i++){
            int temp = uglyNums[indn[i]]*times[i];
            
            if(temp<tempmin){
               tempmin = temp; //更新最小值
               res = i;
            }
         }
         indn[res]++;
         // 通过这个判断跳过重复值。
         if(tempmin == uglyNums[count-1]){
            continue;
         }
         // cout<<tempmin<<"  ";
         uglyNums.push_back(tempmin);    
         count++;
      }
      return uglyNums[n-1];
   }
};
// 这个思路和我的完全一样，我们可以借鉴一下为他这个连续if来排除重复的操作
// 还有这个3个min的操作，因为我没想到这个对重复的处理，所以花费了额外的时间复杂度。
class Solution {
public:
	int nthUglyNumber(int n) {
		vector<int> dp(n, 0);
		dp[0] = 1;
		int p2 = 0, p3 = 0, p5 = 0;
		for (int i = 1; i < n; i++) {
			dp[i] = min(min(dp[p2] * 2, dp[p3] * 3), dp[p5] * 5);
			if (dp[i] == dp[p2] * 2)
				p2++;
			if (dp[i] == dp[p3] * 3)
				p3++;
			if (dp[i] == dp[p5] * 5)
				p5++;
		}
		return dp[n - 1];
	}
};



// 优先队列的使用方式，但是时空效率很差劲。
class Solution {
public:
   typedef long long LL;
   const int coeff[3] = {2, 3, 5};
   int nthUglyNumber(int n) {
      // FIXME:但是这里为什么是greater
      priority_queue<LL, vector<LL>, greater<LL> > pq;
      set<LL> s; 
      //定义集合s便于判断一个丑数是否被遍历过

      pq.push(1);
      s.insert(1);
   
      for(int i = 1; ;i++){
         LL x = pq.top(); pq.pop();
         if(i == n) return x;
         for(int j = 0; j < 3; j++){
            // 每次都把最小值*3个数的值插入最小值有限的队列中，然后弹出到第n个最小值即可。
               LL x2 = x * coeff[j];
               if(!s.count(x2)) {s.insert(x2); pq.push(x2);}
         }
      }
   }
};


// -----------------------------------------test--------------------------------
// 在这个地方编写测试样例并进行测试；
int main()
{
    std::cin.get();
}