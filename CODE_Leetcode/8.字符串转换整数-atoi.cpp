/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
class Solution {
public:
    int myAtoi(string s) {
        // 需要注意的点，怎么去判断是否大于>int_max
        // +-号，后面的非符号字符将会被省略
        // 最终输出的是int
        if (s.empty()) return 0; 
        int n = s.size();
        // 设计一个判断纯整数的，以及一个有+-号判断的函数？好像没必要，前置的+没必要了
        long int outofRange = 0; // 这种写法实际上也不是特别好，要想想怎么判断，用位运算去做会不会好点。
        int res = 0;
        size_t index = 0; bool isNegative = false; bool isNumber = false; bool isOverFlow = false;
        // 这里需要嵌入对index 大小的判断，实际上+在最外城和加在每一句判断中好像并不会增加复杂度，因为都是不回头的单次遍历
        while (index < n && s[index] == ' ') ++index;
        if (index < n && s[index] == '-') {
            isNegative = true; ++index;
        }
        else if (index < n && s[index] == '+')
            ++index;
        // 接下来应该是蠢整数判断,这里需要注意的是数组是逆序的
        
        unsigned long int bitLoc = 1;
        while (s[index] == '0') ++index;
        while (index < n && s[index] >= '0' && s[index] <= '9') {
            isNumber = true;
            outofRange = outofRange * 10 + (s[index]-'0');
            
            if (bitLoc >= INT_MAX) {
                return isNegative ? INT_MIN : INT_MAX;
            }
            bitLoc *= 10; index++;
        }
        // 判断是否越界
        if (isNumber) {
            if (isNegative) outofRange = -outofRange;
            if (outofRange > INT_MAX || outofRange < INT_MIN) {
                return isNegative ? INT_MIN : INT_MAX;
            }
            return outofRange; // 隐式类型转换
        }
        return 0;
    }
};
// @lc code=end

