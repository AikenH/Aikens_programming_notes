/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
 */
#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<string>
#include<queue>
using namespace std;
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
private:
    vector<string> res;
    unordered_set<string> tempres;
    // string temp;
public:
    vector<string> permutation(string s) {
        if(s.empty()) return {};
        helpfuc(s,0);
        for(auto element: tempres){
            res.emplace_back(element);
        }
        return res;
    }
    void helpfuc(string& s, int first){
        int n = s.size();
        // based cases return vector
        if(first == n) {
            tempres.insert(s);
            return;
        }
        for(int i=first;i<n;i++){
            // 记得这里只能是和first换，不然就会换回来了。
            // NOTE: 字符串的排列时考虑了重复情况的，所以我们最好是使用hashset
            swap(s[i],s[first]);
            helpfuc(s,first+1);
            swap(s[i],s[first]);
        }
        return;
    }
};


