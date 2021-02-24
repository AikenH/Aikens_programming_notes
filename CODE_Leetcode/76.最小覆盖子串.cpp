/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
#include<string>
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if(s.empty() || s.size()<t.size()) return {};
        unordered_map<char,int> need,windows; 
        for(char temp: t) need[temp]++; //存储所有需要的字符
        
        // 初始化双指针和判断指针
        int right=0, left=0;
        int valid =0; int n = need.size(); 
        // 存放结果
        int len = INT_MAX; int s_index = 0;
        
        while(right<s.size()){
            char c = s[right];
            right++;
            if(need.count(c)){
                windows[c]++;
                // 考虑到重复数值的出现
                if(windows[c] == need[c])
                    valid++;
            }
            while(valid == need.size()){
                if(right-left<len){
                    s_index = left;
                    len = right-left;
                }
                char d = s[left];
                left++;
                if(need.count(d)){
                    // 考虑到有多个对应元素，而我们pop的时候只有当临界值需要修改状态
                    if(windows[d]== need[d])
                        valid--;
                    windows[d]--;
                }
            }
        }
        return len==INT_MAX?"":s.substr(s_index,len);

    }
};
// @lc code=end

