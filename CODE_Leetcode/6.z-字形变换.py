#
# @lc app=leetcode.cn id=6 lang=python
#
# [6] Z 字形变换
#

# @lc code=start
class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        temps = ''
        if numRows == 1:
            temps = s
        else:
            for i in range(numRows):
                # 迭代进行，将每个index 添加到outofrange就行
                index = 0 
                while (index) <= (len(s)+ 2*numRows -2):
                    
                    if i == 0 or i == numRows-1:
                        try:
                            temps += s[index + i]
                            index += 2*numRows -2
                        except IndexError:
                            break
                    else:
                        if index == 0:
                            try:
                                temps += s[i]
                            except IndexError:
                                break
                        else:
                            try:
                                temps += s[index - i]
                            except IndexError:
                                break
                            try:
                                temps += s[index + i]
                            except IndexError:
                                break
                        index += 2*numRows -2
        return temps

                
                
# @lc code=end
# if __name__ == "__main__":
#     test = Solution()
#     print(test.convert('ABCDE',4))