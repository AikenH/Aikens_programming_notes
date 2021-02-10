/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board,0,0);
    }
    bool backtrack(vector<vector<char>>& board, int r, int c){
        // 这里的这个逻辑我有点没搞清楚，为什么要全进行m-n的遍历，我觉得是多余的
        // 首先继续宁测试，如果不对再说
        if(r==9) 
            return true;
        // 判断下一个位置：
        int nextr = r, nextc =c;
        nextc++;
        if(nextc>=9) {
            nextr++; 
            nextc=0;}

        // 判断返回值
        if(board[r][c]!='.') {
            // 
            if(backtrack(board,nextr,nextc))
                return true;
            else
                return false;
        }

        for(char ch = '1'; ch<='9'; ch++){
            if(!isValid(board, r, c, ch)) continue;
            
            board[r][c] = ch;
            if(backtrack(board,nextr,nextc)) return true;
            // 问题应该是出在，找到了解以后没有返回的问题
            board[r][c] = '.';
            
        }
        return false;

    }
    bool isValid(vector<vector<char>>& board, int r, int c, char ch){
        // 从上到下填，但是我们还是需要搜索整张棋盘，
        for (int i = 0; i<9; i++) {
            if(board[r][i] == ch) return false;
            if(board[i][c] == ch) return false;
            if(board[(r/3)*3+i/3][(c/3)*3 +i%3]==ch) return false;
        }
        return true;
    }
};
// @lc code=end

