#
# @lc app=leetcode.cn id=8 lang=python
#
# [8] 字符串转换整数 (atoi)
#

# @lc code=start
class Solution(object):
    def myAtoi(self, s):
        """
        :type s: str
        :rtype: int
        """
        ans,i,negative,pos = 0, 0, False,0 
        boundry = (1<<31) -1
        for v in s:
            if i == 0 and v == '-':
                negative = True
                boundry += 1
                i += 1
                pos += 1
                if pos >= 2: break
            elif v == ' ':
                if pos >= 1:break
                else: continue
            elif v == '+':
                pos += 1
                if pos >= 2: break
            else:
                try:
                    ans = ans *10 + int(v)
                    i += 1
                    pos += 1 
                    if ans > boundry:
                        return -2147483648 if negative else 2147483647
                except ValueError:
                    break
            
        return -ans if negative else ans
# @lc code=end

# if __name__ == "__main__":
#     a = Solution()
#     print(a.myAtoi('+0 123'))

# NOTE: '+-' 在前这种情况竟然要当成非字符串输出，我是没想到的，有点离谱
# NOTE: 中间因为空格断开的情况