/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
#include<string>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        // 这题实际上也能用动态规划来解答，但是这题的动态规划效果一般
        // TODO：我们也可以用马拉车算法解决学习一下
        // 我们python中写的是什么玩意，我有点没看懂，后面再看看是怎么做的,我觉得可以不用看，思路太傻逼了。但是可以分析测试样例。
        //使用简单的递归思想用双指针的方式来解决奇偶不同的情况
        string res;
        for(int i=0;i<s.size();i++)
        {
            string S1 = findPalindrome(s,i,i);
            string S2 = findPalindrome(s,i,i+1);
            res = res.size()>S1.size()?res:S1;
            res = res.size()>S2.size()?res:S2;
        }
        return res;
    }
    string findPalindrome(const string& s, int l, int r)
    {
        while(l>=0 && r<s.size() && s[l]==s[r])
        {
            l--;r++;
        }
        // substr 参数是起始点和长度
        return s.substr(l+1,r-1-l);
    }
};
// @lc code=end

