/*leetcode中算法的测试样板
*/
#include<vector>
#include<unordered_map>
#include<string>
// -----------------------------------------question--------------------------
这实际上都有点是旧时代的算法题目了，考应该是不会再考了，但是思想还是要掌握

请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

 

示例 1：

输入：s = "We are happy."
输出："We%20are%20happy."
 

限制：

0 <= s 的长度 <= 10000

// -----------------------------------------ans--------------------------------
// 这个方法也太 out of data了, 我是傻逼， 我是傻逼， 我是傻逼， 我是傻逼， 我是傻逼， 我是傻逼，
// 这里首先还要resize这个string，我没做 
// class Solution {
// public:
//     string replaceSpace(string s) 
//     {
//         // 判断特殊情况：数组为空或者 nullptr(指定的输入类型是string所以应该是不可能的把)
//         unsigned int originsize = s.size()+1;
//         if (originsize <= 1)
//             return;
//         for (int i = 0; i <originsize  ; i++)
//         {
//             int count = 0;
//             if (s[i] == ' ')
//                 count++;
//         }
//         unsigned int finalsize = originsize + count * 2;
//         // 因为size和index之间有1的偏差所以这里是--i而不是i--
//         j = finalsize - 1;
//         for (int i = originsize; i >= 0; --i)
//         {
//             if (s[i] == ' ')
//             {
//                 s[j - 2] = '%';
//                 s[j - 1] = '2';
//                 s[j] = '0';
//             }
//             else
//             {
//                 s[j] = s[i];
//             }

//         }
//         return s;
//     }
// };
// -----------------------------------------ans2--------------------------------
class Solution {
public:
    string replaceSpace(string s) {
        string output;
        for (auto& tps : s)
        {
            if (tps == ' ')
                output.append("%20");
            else
                // output.append(tps);
                output += tps;
                //output.push_back(tps);
        }

        return output;
    }
};
// 这里其实有好几种方法把 push_back , append , +=
// append ，为什么在append元素组的子元素的时候会出错呢？
// 还有stringbuilder的方法，直接进行替换就好了（但是原题解应该是要在原本下面的空间把，这样有啥意义呢）
// https://blog.csdn.net/csxypr/article/details/92378336
// 也可以分割和拼接，但是这样的方法没有意义
// resize

// 在原数组上的replace,不是直接指定子袁术，而是要的要指定位置，或者指定迭代器的方法。
class Solution {
public:
    string replaceSpace(string s) {
        unsigned int originsize = s.size() + 1;
        // 这个每次都要变换size的判断成本太高了；
       /* for (int i = 0; i < (s.size() + 1); i++)
        {
            if (s[i] == ' ')
                s.replace(i, 1, "%20");
        };*/
        // 用下面这种方式写循环就极大的降低了判断两，不需要调用那个函数了。
        i = 0;
        while (s[i] != '\0')
        {
            if (s[i] == ' ')
            {
                s.replace(i, 1, "%20");
                i += 2;
            }
            i++;
        }
        return s;
    }
};
// -----------------------------------------test--------------------------------

// 在这个地方编写测试样例并进行测试；
int main()
{
    std::cin.get();
}