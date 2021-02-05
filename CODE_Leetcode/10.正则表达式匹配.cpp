/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        auto matches = [&](int i, int j) {
            if (i == 0) {
                return false;
            }
            if (p[j - 1] == '.') {
                return true;
            }
            return s[i - 1] == p[j - 1];
        };

        vector<vector<int>> f(m + 1, vector<int>(n + 1));
        f[0][0] = true;
        for (int i = 0; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    f[i][j] |= f[i][j - 2];
                    if (matches(i, j - 1)) {
                        f[i][j] |= f[i - 1][j];
                    }
                }
                else {
                    if (matches(i, j)) {
                        f[i][j] |= f[i - 1][j - 1];
                    }
                }
            }
        }
        return f[m][n];
    }
};

// class Solution {
// private:
    
// public:

//     bool isMatch(string& s, string& p) {
//         // 空值测试
//         vector<vector<bool>> DP (s.size(),vector<bool>(p.size(),false));
//         if(p.empty()) return s.empty();
//         return findMatch(s,p,0,0);
        
//     }

//     bool findMatch(const string& s , const string& p,int si, int pi);
// };
// bool Solution::findMatch(const string& s, const string& p, int si, int pi) {
//     // if(p.empty()) return s.empty();
//     int s_ize = s.size(), p_size = p.size();
//     if (pi>=p_size && si<s_ize) return false;
//     if (pi>=p_size && si>=s_ize) return true;
//     // 第二种，匹配到了*号的情况
//     // 由于关键的*的个数，实际上是一种不确定的情况，而只要有一种情况符合就只要当True即可
//     // 所以用递归的方法去做还是挺合适的
//     if(p[pi+1]=='*')
//     {
//         if(p[pi]==s[si] || (p[pi] == '.'&&si<s_ize))
//         {
//             //实际上三者其中一个的最优就对了
//             return findMatch(s,p,si+1,pi+2) || findMatch(s,p,si+1,pi) || findMatch(s,p,si,pi+2);
//         }
//         else
//         {
//             return findMatch(s,p,si,pi+2);
//         }
//     }
//     // 三种可能性，首先先判断最简单的清康 .或者相等的情况
//     if(s[si]==p[pi] || p[pi]=='.' && si<s_ize)
//     {
//         return findMatch(s,p,si+1,pi+1);
//     }

//     return false;
    
// }
// @lc code=end
    // 该问题的主要困难就在*需要实现的是能匹配任意的字符数；
    // 我的写法问题很多，比如说 aaa 和a*a这种条件，我没办法判断到底最后这个*重复了几次
    // 我用的贪婪判断策略就很失败，而且写的太长了易读性也很擦
    // 这题由于.的特殊性的话，好像用python的in更好用一点
        // int i=0, j=0;
        // // 好像还是对i进行遍历比较好
        // // 错了，漏洞百出
        // while(i<s.size()){
        //     if(j<p.size()){
        //         // 如果使用或的情况下使用++会导致两次判断调用的i是不一致的吗？
        //         if (s[i]==p[j] || p[j] == '.') {
        //             i++;j++;continue;
        //         }
        //         // 实际上这是一个递归问题吧，用helpmatch来match这个*的情况
        //         if(p[j] == '*' ){
        //             // .*这种无敌的情况不能忘
        //             if(p[j-1] == s[i] || p[j-1] == '.') {
        //                 i++; continue;
        //             }
        //                 // 跳过当前的值
        //             j++;continue;
        //         }
        //         else if (p[j+1] == '*') {
        //             j += 2; i++; continue;
        //         }
        //         return false;
        //     }
        //     // p遍历完了而且i还没遍历完。
        //     return false;
        // }
        // // i 遍历完了 j还没遍历完，那怎么操作
        // if(j<p.size())
        // {
        //     if (p[p.size()-1] != '*') return false;
        //     if(p[j]!='*') j++;
        //     if(p[j]!= '*') return false;
        //     while(j+2<p.size()){
        //         if(p[j+2]!='*')
        //             return false;
        //         j = j+2;
        //     }
        // }
        // return true;