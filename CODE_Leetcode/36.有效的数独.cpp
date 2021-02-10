/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> row (9, vector<int>(9,0));
        vector<vector<int>> col (9, vector<int>(9,0));
        vector<vector<int>> box (9, vector<int>(9,0));
        // 没啥好说的，就遍历就行了，这个实际上用的都是9*9的矩阵，我感觉可以通过两个循环来节省空间
        // 实际上就是一种hash的解法。
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] == '.'){
                    continue;
                }
                int val = board[i][j] - '1';
                int box_index = (i/3) * 3 + j/3;
                if(row[i][val] == 0 && col[j][val] == 0 && box[box_index][val] == 0){
                    row[i][val] = 1;
                    col[j][val] = 1;
                    box[box_index][val] = 1;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end

