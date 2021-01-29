/*leetcode中算法的测试样板
*/
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
// -----------------------------------------question--------------------------

// -----------------------------------------ans--------------------------------
//解决方式入口函数
class Solution
{
private:
	
public:
	// int cuttingRope(int n)
	// {
    //     // 这里是特殊的一些情况，
    //     if(n<2)
    //         return 0;
    //     else if(n == 2)
    //         return 1;
    //     else if (n==3)
    //         return 2;
	// 	// 每一段的长度都需要是整数。
	// 	// 初始化结果矩阵:要记得index和绳子的长度有加一的关系,先修改成直接对应的关系好了
    //     // FIXME: 有一点重要的在于，我们不是每一步都要迭代到底，切割本身就是一种分别情况。
    //     // TODO：这个初始值设置怎么界定？
	// 	vector<int> maxarray(n+1, 0);
	// 	maxarray[0] = 0;
	// 	maxarray[1] = 1;
    //     maxarray[2] = 2;
    //     maxarray[3] = 3;
	// 	// bottom-up的循环
	// 	for (int i = 4; i <= n; i++)
	// 	{
	// 		int maxres = 1;
	// 		// 每个数值的全部情况,由于是bottom-up的动态规划，不用担心下面迭代上来的情况没有值
	// 		for (int j = 1; j <= i / 2; j++)
	// 		{
	// 			int tmp = maxarray[j]*maxarray[i=j];
    //             if(tmp >maxarray[i]){
    //                 maxarray[i] = tmp;
    //             }
	// 		}
	// 	}
    //     return maxarray[n];

	// }
    但是我们发现这样的算法的时间效率并没有变高，这是因为这个多重判断的时间复杂度的问题吗，不应该啊。
int cuttingRope(int n)
{
    if(n <= 3)  return n-1;
    int times;
    if (n%3==1)
    {
        times = n/3 -1;
        return pow(3,times)*4;
    }
    else if(n%3==2)
    {
        times = n/3;
        return pow(3,times)*2;
    }

    times = n/3;
    return pow(3,times);

}
而通过循环减的方法，我们发现时间复杂度突然小了很多，这是为啥，这是因为在普遍size的情况下，执行了过多的判断吗？
所以最终选用的方法还是下面这种把？
int cuttingRope(int n) {
    if(n <= 3)  return n-1;
    int res = 1;
    while(n > 4)
    {
        n    = n - 3;           //尽可能地多剪长度为3的绳子
        res  = res * 3;         
    }
    return res * n;
}
改进判断过多的情况：
int cuttingRope(int n)
{
if(n <= 3)  return n-1;
int times = n/3;
int remain = n-3*times;
if(remain == 1)
    return pow(3,times-1)*4;
return pow(3,times)* remain?pow(3,times)*remain:pow(3,times);
}
};

// -----------------------------------------test--------------------------------
// 在这个地方编写测试样例并进行测试；
int main()
{
    std::cin.get();
}