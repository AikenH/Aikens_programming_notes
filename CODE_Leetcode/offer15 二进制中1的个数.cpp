/*leetcode中算法的测试样板
*/
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
// -----------------------------------------question--------------------------

// -----------------------------------------ans--------------------------------
class Solution
{
public:
    int hammingWeight(uint32_t n){
        // 三种写法，实际上1-2是一类，所以写两种就好了。
        // uint32_t i = 1;
        // int count = 0;
        // while(i){
        //     if (n&i)
        //         count++;
        //     i = i<<1; // 别忘了这个赋值
        // }
        // return count;

        // method 3 
        unsigned int count = 0;
        while(n){
            n = n & (n-1);
            ++count;
        }
        return count;
    }

};
// -----------------------------------------test--------------------------------
// 在这个地方编写测试样例并进行测试；
int main()
{
    std::cin.get();
}