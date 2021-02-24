/*
 * @lc app=leetcode.cn id=241 lang=cpp
 *
 * [241] 为运算表达式设计优先级
 */

// @lc code=start
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        int n = input.size();
        vector<int>a; vector<int>b;
        for(int i = 0; i<n;i++){
            char c = input[i];
            if(c=='*' || c=='+' || c=='-'){
                a = diffWaysToCompute(input.substr(0,i));
                b = diffWaysToCompute(input.substr(i+1,n-i-1));
                // 由于我们已经有了c所以我们通过这个定义一个运算
                for(int nums1:a){
                    for(int nums2:b){
                        int temp = calculate(nums1,nums2,c);
                        res.emplace_back(temp);
                    }
                }
            }
            
        }
        // basecase!!! 当我们发现里面没有运算符的时候，就说明这是一个单纯的数字
        if(res.empty()){
            res.emplace_back(stoi(input));
        }
        return res;

    }
    int calculate(const int& num1, const int& num2, char& op){
        if(op=='+'){
            return num1+num2;
        }else if(op=='-'){
            return num1-num2;
        }else if(op=='*'){
            return num1*num2;
        }
        return {};
    }
};
// @lc code=end

