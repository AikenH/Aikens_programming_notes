/*
 * @lc app=leetcode.cn id=1081 lang=cpp
 *
 * [1081] 不同字符的最小子序列
 */

// @lc code=start
class Solution {
public:
    string smallestSubsequence(string s) {
        if(s.empty()) return {};
        vector<int> count(256,0);
        stack<int> store;
        vector<bool>isStored(256,false);
        // 初始化后续的存储情况
        for(char c:s){
            ++count[c];
        }
        // 开始进行判断，遍历所有的s中的数
        for(char c:s){
            --count[c];
            if(isStored[c]) continue;
            while(!store.empty() && c<store.top()){
                // 如果里面已经没有第二个这个数字了
                if(count[store.top()]==0)
                    break;
                
                isStored[store.top()] = false;
                store.pop();
                
            }
            store.push(c);
            isStored[c] = true;
        }
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

