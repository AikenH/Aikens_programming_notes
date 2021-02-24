/*
 * @lc app=leetcode.cn id=316 lang=cpp
 *
 * [316] 去除重复字母
 */

// @lc code=start
#include<vector>
#include<stack>
#include<string>
using namespace std;
class Solution {
public:
    string removeDuplicateLetters(string s) {
        if(s.empty()) return {};
        // 初始化需要的存储数据结构
        vector<int> countAl(256,0); 
        vector<bool> countSt(256,false);
        stack<int> store;
        // 初始化count数组
        for(auto t: s){
            countAl[t]++;
        }
        for(char c: s){
            countAl[c]--;
            if(countSt[c]) continue;
            while(!store.empty() && store.top()>c){
                // 如果top后面没有了
                if(countAl[store.top()]==0)
                    break;
                // 如果还有就pop
                countSt[store.top()] = false;
                store.pop();
            }
            store.push(c);
            countSt[c] = true;
        }
        // 对stack中的字符进行反转然后输出
        string res;
        stack<char> temp;
        while(!store.empty()){
            temp.push(store.top());
            store.pop();
        }
        while(!temp.empty()){
            res.push_back(temp.top());
            temp.pop();
        }
        return res;
    }
};
// @lc code=end

