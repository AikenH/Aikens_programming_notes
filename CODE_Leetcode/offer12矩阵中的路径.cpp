/*leetcode中算法的测试样板
*/

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;
// -----------------------------------------question--------------------------
// 请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一格开始，每一步可以在矩阵中向左、右、上、下移动一格。如果一条路径经过了矩阵的某一格，那么该路径不能再次进入该格子。例如，在下面的3×4的矩阵中包含一条字符串“bfce”的路径（路径中的字母用加粗标出）。

// [["a","b","c","e"],
// ["s","f","c","s"],
// ["a","d","e","e"]]

// 但矩阵中不包含字符串“abfb”的路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入这个格子。

//  

// 示例 1：

// 输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
// 输出：true
// 示例 2：

// 输入：board = [["a","b"],["c","d"]], word = "abcd"
// 输出：false
//  

// 提示：

// 1 <= board.length <= 200
// 1 <= board[i].length <= 200

// -----------------------------------------ans--------------------------------
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        // 实现的问题：判断的就是相应的邻格中有没有相应的元素
        // 怎么判断是否重复，切换成一个无表示的值？NULL行不行？
        // 总结一下：第一步find，第二部search（4 blocks），第三步替换成NULL，第四步移动格子。
        // find start (但是这样有个问题就是起始节点不是单一的，有可能有重复的起始节点。)
        int s_index = 0, s_jndex = 0;
        bool res = false;
        for(int i=0;i<board.size();i++){
            for (int j=0;j<board[i].size();j++){
                if (board[i][j] == word[0]){
                    s_index = i; s_jndex=j;
                    res = helpsearch(board, word, i,j,0);
                    if(res)
                        return true;
                    // board[i][j] = NULL; //只能临时控制，不然会导致后续出问题
                }
            }
        }
        return false;
    }
    bool helpsearch(vector<vector<char>>& board,string word, int idex, int jdex, int kdex){
        // 前面的方法遍历所有可能的起始点，但是这样的话，修改重复数组就完蛋了（用迭代的方法来实现临时的赋值）
        // 迭代搜索
        if(kdex == word.size())
            return true;
            
        if(idex<0 || idex>=board.size() || jdex<0 || jdex >=board[0].size())
            return false;
        
        bool res = false;

        if (board[idex][jdex] == word[kdex]){
            board[idex][jdex] = '\0';
            // 四种情况这里要体现一下，但是如果用递归的方式写入四个节点的话，好像复杂度有点问题
            
            bool temp = helpsearch(board, word, idex+1, jdex, kdex+1) || helpsearch(board, word, idex-1, jdex, kdex+1)\
                 || helpsearch(board, word, idex, jdex-1, kdex+1) || helpsearch(board, word, idex, jdex+1, kdex+1);
            
            res = true && temp;
            
            board[idex][jdex] = word[kdex];
        }
        return res;
    }
};

// -----------------------------------------test--------------------------------
// 在这个地方编写测试样例并进行测试；
int main()
{
    std::cin.get();
}