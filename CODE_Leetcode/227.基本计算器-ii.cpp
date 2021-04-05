/*
 * @lc app=leetcode.cn id=227 lang=cpp
 *
 * [227] 基本计算器 II
 */

// @lc code=start
class Solution {
public:
    int calculate(string s) {
        int index = 0; int res = 0; int num = 0;
        int temp = 0;
        stack<int> cal;
        while(index<s.size()){
            if(isdigit(s[index])){
                num += (int)(s[index]-'0');
            }
            switch(s[index]){
            case '+': 
                cal.push(num);
                break;
            case '-': 
                cal.push(-num);
                break;
            case '*': 
                temp = cal.top();
                cal.pop();
                cal.push(temp * num);
                break;
            default:
                temp = cal.top();
                cal.pop();
                cal.push(num/temp);
            }
        }
        return accumulate(cal.begin(),cal.end(),0);
    }
};
// @lc code=end

