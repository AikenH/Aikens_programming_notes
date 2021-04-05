/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // 研究基于扩散的思路，要想四个方向进行搜索
        if(grid.empty()) return 0;
        // 使用BFS或者DFS进行搜索
        // method1：BFS搜索的话，需要装入的是每一步的坐标
        queue<pair<int,int>> que;
        int count = 0;
        // 如果是在线oj，可以使用vector（2）进行
        // 首先找到相应的一的地方
        int n = grid.size(); int m = grid[0].size();
        for(int i = 0; i<n;i++){
            for(int j = 0;j <m;j++){
                // 搜索到第一个非0的点
                if(grid[i][j] == '1'){
                    ++count;  grid[i][j] = '0';
                    que.push({i,j});
                    while(!que.empty()){
                        // 当数组没空的时候就需要对各个方向进行搜索，这样是不是嵌套太多层了
                        int row = que.front().first; int col = que.front().second; 
                        grid[row][col] = '0';
                        que.pop();
                        // 进行四个方向的搜索，要考虑到相应的边界约束
                        if(row-1>=0 && grid[row-1][col] == '1') {
                            que.push({row-1, col});
                            grid[row-1][col] = '0';
                        }
                        if(col-1>=0 && grid[row][col-1] == '1') {
                            que.push({row, col-1});
                            grid[row][col-1] = '0';
                        }
                        if(row+1<n && grid[row+1][col] == '1') {
                            que.push({row+1, col});
                            grid[row+1][col] = '0';
                        }
                        if(col+1<m && grid[row][col+1] == '1') {
                            que.push({row, col+1});
                            grid[row][col+1] = '0';
                        }
                    }
                }
            }
        }
        return count;
    }
};
// @lc code=end

