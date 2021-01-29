/*leetcode中算法的测试样板
*/
#include<vector>
#include<unordered_map>
// -----------------------------------------question--------------------------

// -----------------------------------------ans--------------------------------
// 内存消耗还行，但是时间消耗才87.是不是应该去掉前面的判断，
class Solution {
public:
    int minArray(vector<int>& numbers) {
        if(numbers[0]<numbers[numbers.size()-1])
            return numbers[0];
        for (int i=1; i<numbers.size();i++)
        {
            if(numbers[i]<numbers[i-1])
                return numbers[i];
        }
        return numbers[0];
    }
};
// -----------------------------------------test--------------------------------
// 在这个地方编写测试样例并进行测试；
int main()
{
    std::cin.get();
}