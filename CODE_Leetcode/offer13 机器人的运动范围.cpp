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
private:
	int subsum(int x)
	{
		// NOTE:这个写法要注意对for循环有一个好的理解，知道到底是象征什么意思。还有第一项空置的含义
		int res = 0;
		for (; x; x /= 10)
		{
			res += x % 10;
		}
		return res;
	}
public:
	int movingCount(int m, int n, int k)
	{
		// 整理思路重新出发
		//NOTE:定义vector的初始化长度，防止vector队内存的动态再分配来影响运行时间
		// (length, value)
		if (!k)
			return 1;
		vector<vector<bool>> visited(m, vector<bool>(n, 0));
		// 起始点初始化
		int ans = 1;
		visited[0][0] = 1;
		// 循环递推,中间需要嵌入是否满足条件的判断。
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				// NOTE:排除边界和不可访问点。当已经访问过的时候直接,但是实际上能不能用跳出的处理呢
				if (i == 0 && j == 0 || subsum(i) + subsum(j) > k) continue;
				// 排除不可达的情况，由于我们是前向遍历，我们只需要考虑他的前一个或者上一个能到达，才行。
				// 这个理论可以好好的分析一下。这样的话，实际上还是有切断的处理的把。（前一个和上一个都就直接换行之类的？）
				if (i - 1 >= 0 && visited[i - 1][j]) {
					visited[i][j] = true;
					ans += 1;

				}
				else if (j - 1 >= 0 && visited[i][j - 1]) {
					visited[i][j] = true;
					ans += 1;
				}
				else
					continue;
			}
		}
		return ans;

	}
};
// -----------------------------------------test--------------------------------
// 在这个地方编写测试样例并进行测试；
int main()
{
    std::cin.get();
}