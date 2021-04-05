/*
 * @lc app=leetcode.cn id=678 lang=cpp
 *
 * [678] 有效的括号字符串
 */

// @lc code=start
class Solution {
public:
    bool checkValidString(string s) {
        // 实际上这是一个加入了正则项表达式的括号有效性判断
        // 统计一下*的数量应该就是行了把
        int count = 0; int allforone = 0;
        for(int i = 0;i<s.size();++i){
            if(s[i] == '(') ++count;
            else if(s[i] == ')') --count;
            // else if(s[i] == '*') ++ allforone;
        }
        // 不行
        return (count+allforone >= 0) || (count-allforone <=0);

    }
};
// @lc code=end

