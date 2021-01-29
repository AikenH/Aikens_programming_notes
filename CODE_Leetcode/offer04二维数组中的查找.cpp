/*leetcode中算法的测试样板
*/
#include<vector>
#include<unordered_map>
// -----------------------------------------question--------------------------
在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
请完成一个高效的函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
示例:
现有矩阵 matrix 如下：

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
给定 target = 5，返回 true。
给定 target = 20，返回 false。
限制：
0 <= n <= 1000
0 <= m <= 1000
// -----------------------------------------ans--------------------------------
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        // 由于输入类型的原因，这应该不可能输入空指针吧。判断会出错.
        // 没有空指针但是有empty vector的情况
        // NOTE:需要注意1.
        if (matrix.empty())
            return false;

        int high = matrix.size(), height = matrix[0].size();
        // std::cout<<high<<" | "<<height<<std::endl;
        bool found = false;
        if(high<=0 || height <=0)
            return false;
        // NOTE：容易出错的地方2（初始化点应该在哪）
        int i=0,j=height-1;
        // NOTE：容易出错的地方3（边界条件怎么设定）（从零开始）
        while(i<high && j>=0)
        {
            if(matrix[i][j]==target)
            {
                found = true;
                break;
            }
            else if(matrix[i][j]<target)
                ++i; //这种没有赋值的情况下应该是一样的，测试结果也一样，但是可以分析一下
            else
                --j;
        }
        return found;
    }
};
// -----------------------------------------test--------------------------------
// 在这个地方编写测试样例并进行测试；
int main()
{
    std::cin.get();
}