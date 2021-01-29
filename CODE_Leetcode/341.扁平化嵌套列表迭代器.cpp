/*
 * @lc app=leetcode.cn id=341 lang=cpp
 *
 * [341] 扁平化嵌套列表迭代器
 */

#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
private:
    int lens;
    int index;
    vector<int> NestIt; // 关键点在于额外辅助数组的构建，但是是否能够预先建立一个比较长的数组
    // FIXME：通过初始化函数，建立一个比较合适的数组长度，从而减少需要额外分配内存的时间代价。
    // Vector的重新初始化方式。

public:
    // TODO:迭代器的表示形式应该怎么写
    // NOTE：这种题目的阅读逻辑应该怎么分析
    NestedIterator(vector<NestedInteger> &nestedList):index(0) {
        helpBuildVec(nestedList);
    }

    void helpBuildVec(vector<NestedInteger> & nestedList){
        for(int i =0;i<nestedList.size();i++)
        {
            if(nestedList[i].isInteger())
                NestIt.push_back(nestedList[i].getInteger()); // 记得要调用取值的函数
            else
                helpBuildVec(nestedList[i].getList());
        }
        lens = NestIt.size();
    }
    
    int next() {
        return NestIt[index++];
    }
    
    bool hasNext() {
        return index < lens; 
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
// @lc code=end

