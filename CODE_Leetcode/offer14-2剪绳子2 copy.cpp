/*leetcode中算法的测试样板
*/
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
// -----------------------------------------question--------------------------

// -----------------------------------------ans--------------------------------
//解决方式入口函数
// 这种写法来解决取余数确实是更方便一点。
class Solution {
public:
    int cuttingRope(int n) {
        if(n <= 3)  return n-1;     //如果n<=3,数字要求至少分为两部分，实际结果的最大值为n-1
        long long res = 1;
        while(n > 4)
        {
            n = n - 3;
            res = res * 3 % 1000000007;
        }
        return res * n % 1000000007;
    }
};

// -----------------------------------------test--------------------------------
// 在这个地方编写测试样例并进行测试；
int main()
{
    std::cin.get();
}