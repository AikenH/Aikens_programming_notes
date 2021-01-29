/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
 */
#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<quene>
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
// TODO：总结一下各种数据类型下的空值return分别怎么表示。
// TODO: 各种类型之间的变化操作的实现。
// TODO: 各类迭代器中的类型
// int to string : to_string
// string to int : stoi()
// 上面两点都开个专题去做把。
class Codec {
public:
    // 实际上该问题还是突出一个三种遍历方式的问题；
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string BTString;
        string SEP = ",";
        string ENDS = "#";
        if(!root){
            BTString.append(ENDS).append(SEP);
            return BTString;
        }
        
        // 前序遍历位置
        // TODO：连续append的表示形式

        BTString.append(to_string(root->val)).append(SEP);
        BTString.append(serialize(root->left)); 
        BTString.append(serialize(root->right)); 
        return BTString;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // 切分字符串方法 find & substr?
        // 我们在这里需要的是一个先进先出的情况，所以实际上是一个Quene的类别
        // 但是好像实际上for循环也能满足这个问题，但是如果我试图使用递归的话，那我应该还是要用队列
        // 长度不固定的问题
        // FIXME:String的空值的情况
        if(data=="")
            return nullptr;
        // NOTE: 通过循环将布不恒等的数值压入队列
        queue<string> q;
        string Tmpstr;
        for(int i = 0; i<data.length();i++){
            if(data[i]==','){
                q.push(Tmpstr);
                Tmpstr.clear();
            }
            else{
                // FIXME：append就不行但是push_back就可以，为什么？
                Tmpstr.push_back(data[i]);
            }
        }
        return helprebuild(q);
    }
    TreeNode* helprebuild(queue<string>& que);
};
TreeNode* Codec::helprebuild(queue<string>& que)
{
    TreeNode* root;
    // if (que.empty())
    //     return nullptr;
    string str = que.front();
    if(str == "#")
    {
        que.pop();
        return nullptr;
    }
    // FIXME：还没有给这个类别建立一个存储空间
    root = new TreeNode();
    root->val = stoi(str);
    que.pop();
    root->left = helprebuild(que);
    root->right = helprebuild(que);
    return root;
}

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

