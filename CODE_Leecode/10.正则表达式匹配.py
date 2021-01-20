#
# @lc app=leetcode.cn id=10 lang=python
#
# [10] 正则表达式匹配
#

# @lc code=start
# FIXME: 从逻辑层面上来说考虑得不够周到，重新思索有没有好的办法把，列举所有情况太不明智
# TODO：用变换的两个边界来做怎么样？
class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        boundary = [0,0]
        for i,v in enumerate(p):
            pass
        
"""
class Solution(object):
    def isMatch(self, s, p):

        # 三种情况：basic，.,*
        s = list(s)
        extra_index = 0 
        for i,v in enumerate(p):
            if s:
                if v == '*':
                    while s[0] == p[i-1] or p[i-1] == '.':
                        try:
                            if s[0] == p[i+1]: break
                        except IndexError:
                            pass

                        s.pop(0)
                        if not s: break
                        
                    
                elif v == '.':
                    s.pop(0)
                else:
                    if v!=s[0] and p[i+1]!='*':
                        return False
                    elif v!=s[0] and p[i+1]=='*':
                        pass
                    else:
                        s.pop(0)
            else:
                break
            extra_index = i
        if s or extra_index < len(p)-1: return False 
        return True
"""
# @lc code=end

# if __name__ == "__main__":
#     solu = Solution()
#     print(solu.isMatch('mississippi','mis*is*p*.'))