#
# @lc app=leetcode.cn id=7 lang=python
#
# [7] 整数反转
#

# @lc code=start
# 👇最基本的solution，但是runtime和 usage都还行？
# 测试一下位置移动符文会不会更好 : 貌似并没有
import math 
class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        y,ans = abs(x),0
        # boundary = (1<<31) -1 if x > 0 else (1>>31) 
        while y != 0:
            # if  math.abs(y)<10:
            #     ans = ans * 10 + y 
            # else:
            ans = ans * 10 + (y % 10)   
            if ans > math.pow(2,31): return 0
            y = y // 10
            
        return ans if x>0 else -ans
        
# @lc code=end
# NOTE:正数和复数的取余数和整除操作是完全不一样的，建议转换成整数在进行操作。
# NOTE: out of range的判断应该再转换过来以后再进行判断
# if __name__ == "__main__":
#     a = Solution()
#     print(a.reverse(-123))
#     pass