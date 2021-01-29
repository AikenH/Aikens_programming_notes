/*leetcode中算法的测试样板
*/
#include<vector>
#include<unordered_map>
// -----------------------------------------question--------------------------

// -----------------------------------------ans--------------------------------
class Solution {
public:
    int fib(int n) {
        // type 1 stupid answer : 大量重复计算问题的发生
        int prea = 0;
        int preb = 1;
        if (n < 2)
            return n > 0 ? n : 0;
        for (int i = 0; i < n - 1; i++)
        {
            int temp = preb;
            preb += prea;
            // FIXME：需要注意的事情在于这个取余是要在中间执行的。
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