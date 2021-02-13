/*
 * @lc app=leetcode.cn id=752 lang=cpp
 *
 * [752] 打开转盘锁
 */

// @lc code=start
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        // 使用回溯法遍历所有的可能性,同时做出特殊的终结判断
        // 同时维护一个最小值,然后最终返回.

        // 正确理解题目的意思(每次只能转动单个转盘,而且只能移动一格)
        // 为什么使用BFS,最短路径,找到了就提前终止,同时是路径问题
        
        if (target.empty()) return -1; // 非法情况约束
        //初始化搜索队列
        // FIXME: 不走回头路这点怎么实现。hash_set?
        queue<pair<string, int>> que;
        unordered_set<string> visited;
        unordered_set<string> dead(deadends.begin(),deadends.end());
        que.emplace("0000", 0);
        // visited.insert("0000");

        while (!que.empty()) {
            //基于多个方向搜索。
            // FIXME: deadends 还没有建立排除的机制。
            string temp = que.front().first;
            
            int depth = que.front().second;
            if (temp == target) return depth;
            que.pop();
            if (visited.find(temp) != visited.end()) continue;
            // if (containsDeadend(temp, deadends)) continue;
            if(dead.find(temp) != dead.end()) continue;
            visited.insert(temp);
            for (int i = -4; i < 0; i++) {
                auto next = moveLock(temp, i);
                que.emplace(next,depth+1);
            }
            for (int i = 1; i < 5; i++) {
                auto next = moveLock(temp, i);
                que.emplace(next,depth+1);
            }
        }
        return -1;
    }
    string moveLock(string s1, int posandPN) {
        //由于实际上是涉及到生存周期的问题，但是实际上好像empalce不用考虑这个
        if (posandPN > 0 && posandPN <= 4)
        {
            if (s1[posandPN-1] == '9') s1[posandPN-1] = '0';
            else
                s1[posandPN-1] += 1;
        }
            
        else if (posandPN < 0 && posandPN >= -4) {
            if (s1[-posandPN-1] == '0') s1[-posandPN-1] = '9';
            else
                s1[-posandPN-1] -= 1;
        }
            
        return s1;
    }
    // bool containsDeadend(const string& s1, vector<string>& deadends) {
    //     for (string temp : deadends) {
    //         if (s1 == temp) return true;
    //     }
    //     return false;
    // }
};
// @lc code=end

