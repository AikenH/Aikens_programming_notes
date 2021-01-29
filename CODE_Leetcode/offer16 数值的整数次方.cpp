/*leetcode中算法的测试样板
*/
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
// -----------------------------------------question--------------------------

// -----------------------------------------ans--------------------------------
// 我本来以为网友的方法有多屌，实际上还没我的好
class Solution {
public:
    double myPow(double x, int n) {
        if(x == 1 || n == 0) return 1;
        double ans = 1;
        long num = n;
        if(n < 0){
            num = -num;
            x = 1/x;
        }
        while(num){
            if(num & 1) ans *= x;
            x *= x;
            num >>= 1;
        }
        return ans;
    }
};

class Solution {
public:
    double myPow(double x, int n) {
        // FIXME：当指数小于等于0的时候
        // FIXME：当上述情况的时候底数为0的情况
        if(!x)
            return 0;
        else if(!n || x==1.0)
            return 1;
        else if (n<0){
            // 转化为正指数来做
            double tmpx = 1.0/x;
            // FIXME: INT_MIN 因为有个占位，所以取个反可能会越界，所以这里一定要是比int长的变量，而且不能在这里直接取反
            // 需要等到变换类型以后再取反
            unsigned int absExp = (unsigned int)(n);
            return normalPow(tmpx,-absExp);
        }
        else{
            return normalPow(x,n);
        }
        
    }
    double normalPow(double x, unsigned int n)
    {
        // 这是最简单的写法，但是实际上我们可以利用乘方的性质；
        // TODO: 可以通过指数型的来缩减计算量。（看看有没有必要把）
        // 有的，不考虑的话时间限制太离谱了。
        if(n == 1)
            return x;
        if(n == 0)
            return 0;
        
        double res = normalPow(x,n>>2);
        res *= res;
        if (1&n)
            res = res * x;
        return res;
    }
};
// -----------------------------------------test--------------------------------
// 在这个地方编写测试样例并进行测试；
int main()
{
    std::cin.get();
}