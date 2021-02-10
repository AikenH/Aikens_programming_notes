/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
#include<vector>
#include<string>
using namespace std;

class Solution {
private:
    vector<vector<string>> res;
public:
    vector<vector<string>> solveNQueens(int n) {
        // 实际上就是全排列啊，不满足再取消就行了。
        // 问题在于怎么设置判断和返回条件。
        
        // 棋盘初始化，我们一列一列的开始遍历。
        vector<string>board(n, string(n,'.'));
        backtrack(board,0);
        return res;
    }
    void backtrack(vector<string>& board, int row){
        int n = board.size();
        if(row>=n) return;
        for(int j=0;j<n;j++){
            // 假如某行的每一个都不合法，那就说明之前的摆法已经没救了。
            if(!isValid(board, row, j)) 
            {
                // cout<<row<<"  "<<j<<endl;
                continue; 
            }
            // cout<<row<<"&"<<j<<"="<<"Q";
            board[row][j] = 'Q';
            if(row == n-1) {
                res.emplace_back(board);
                // cout<<endl;
                board[row][j] = '.';
                continue;
            }
            backtrack(board, row+1);
            board[row][j] = '.';
        }
        return;
    }
    bool isValid(vector<string>& board, int row, int col){
        /* 对三种情况进行判断，上方，左前方和右前方
        由于我们是从上往下添加的，所以下方的情况暂时不用考虑 */

        int n = board.size();
        // situation1
        for(int i = row; i>=0; i--){
            if(board[i][col] == 'Q') return false;
        }
        // situation2 左上角
        int offset = 0;
        for(int i = row; i>=0; i--){
            if(col-offset<0) break;
            if(board[i][col-offset] == 'Q') return false;
            offset++;
        }
        // situation3 右上角
        offset = 0;
        for(int i = row; i>=0; i--){
            if(col+offset>=n) break;
            if(board[i][col+offset] == 'Q') return false;
            offset++;
        }
        return true;
    }
};
// @lc code=end

