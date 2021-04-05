/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 */
#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<list>
#include<string>
#include<stack>
#include<queue>
#include<set>
using namespace std;
// @lc code=start

class Solution {
public:
    string addStrings(string num1, string num2) {
        if (num1.empty()) return num2;
        if (num2.empty()) return num1;
        // 首先这是一个大数相加的问题，所以在这里统计一个进位符号
        // 其中的关键问题在于插入string的方式把
        string res;
        int index1 = num1.size() - 1;
        int index2 = num2.size() - 1;
        int addInAd = 0;
        while (index1 >= 0 || index2 >= 0 ) {
            int temp1 = index1>=0? num1[index1]:'0';
            int temp2 = index2>=0? num2[index2]:'0';
            int tempres = addInAd + temp1 + temp2 - 2 * '0';
            
            addInAd = 0;
            if (tempres >= 10) {
                tempres -= 10; addInAd = 1;
            }
            // cout<<res<<" ";
            char text = '0' + tempres;
            res.push_back(text);
            index1--; index2 --; 
        }
        // FIXME:两个同时结束但是还有进位没有结算的时候
        if(addInAd==1) res.insert(0,1,'1');
        return res;
    }
};

// @lc code=end

