/*
 * @lc app=leetcode.cn id=887 lang=cpp
 *
 * [887] 鸡蛋掉落
 */

// @lc code=start
#include<vector>
using namespace std;
#include<algorithm>

class Solution {
private:
    // bool isdefined = false;
    // vector<vector<int>> mindrop;
public:
    int superEggDrop(int K, int N) {
        if(!N) return 1;
        if(K==1) return N;
        vector<vector<int>> DP (K, vector<int> (N+1,N+1));
        // 要记住鸡蛋的个数要和序号有-1的关系
        // 状态初始化，如果只有一个鸡蛋的话，就需要从头到尾遍历
        for(int i =0;i<N+1;i++) DP[0][i] = i; // 刚刚这里写错了
        for(int i =0;i<K;i++) DP[i][0] = 0;
        for(int i =0;i<K;i++) DP[i][1] = 1;
        // 进入状态转移的循环阶段，Bottom-UP
        for(int i =1;i<K;i++)
        {
            for(int j=1;j<N+1;j++)
            {
                // 进行二分法优化。

                // // runtime limit， so we must optimal it .
                // for(int iner=1; iner<=j;iner++)
                // {
                //     // 最内层循环进行最优先的迭代，也就是模拟上限变化的过程
                //     // max是计算出最差情况下的状态转移方程 min是指最优选择
                //     DP[i][j] = min(DP[i][j], 1+max(DP[i-1][iner-1],DP[i][j-iner]));
                // }
                int l=1, r=j;
                int iner;
                while(l<=r)
                {
                    iner = (l+r)>>1;
                    if (DP[i-1][iner-1]<= DP[i][j-iner]) {
                        l = iner+1;
                    }else{
                        r = iner-1;
                    }
                }
                iner = r;
                DP[i][j] = min(DP[i][j], 1+max(DP[i-1][iner-1],DP[i][j-iner]));
                
            }
        }
        return DP[K-1][N];
    }
};
// @lc code=end

        // if(!K || !N) return 0;
        // if(K==1) return N;
        // if(N==1) return 1;
        // int minstep = N+1;
        // // 这个思想我是理解了，如果不使用dp tabble的思路的话，还是很清晰的，但是时间复杂度无法减小。
        // // 主要就是，他的那个外层在不断的变小，也就是那个表的上界N在不断的迭代，如果我们bottom-up的话，

        // for (int i =0;i<=N;i++)
        //     minstep = min(minstep,max(superEggDrop(K-1,N-1), superEggDrop(K,N-i))+1);
        // // mindrop[K][N] = minstep;
        // return minstep;