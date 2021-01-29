/*leetcode中算法的测试样板
*/
#include<vector>
#include<unordered_map>
// -----------------------------------------question--------------------------

// -----------------------------------------ans--------------------------------
// 如何归化成斐波那契数列，同时分析初始情况的不同。
class Solution {
public:
    int numWays(int n) {
        int prea = 0;
        int preb = 1;
        if(n==0 || n==1)
        {
            return 1;
        }
        for (int i = 0; i < n ; i++)
        {
            int temp = preb;
            preb += prea;
            preb = preb % (int)(1e9 + 7);
            prea = temp;
        }
        return preb;
    }
};
// -----------------------------------------test--------------------------------
// 在这个地方编写测试样例并进行测试；
int main()
{
    std::cin.get();
}