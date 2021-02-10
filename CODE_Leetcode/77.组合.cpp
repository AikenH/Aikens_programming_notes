/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> res;
public:
    vector<vector<int>> combine(int n, int k) {
        if (k<=0 || n<=0) return res;
        vector<int> tempv;
        backtrack(n,k,0 ,tempv);
        return res;
    }
    void backtrack(int n, int k, int start,vector<int> tempv){
        if(tempv.size() == k) res.emplace_back(tempv);
        for(int i =start; i<n;i++){
            tempv.push_back(i+1);
            backtrack(n,k,i+1,tempv);
            tempv.pop_back();
        }
    }
};
// @lc code=end

