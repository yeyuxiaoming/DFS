/*200:给你一个由?'1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
*/
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
            if(grid[i][j] == '1'){
                count++;
                dfs(grid,i,j);
            }
          }
        }
        return count;
    }
    void dfs(vector<vector<char>>& grid, int x,int y) {
        if(x < 0 || y < 0 || x == grid.size() || y == grid[0].size() || grid[x][y] == '0') {
            return ;
        }
        grid[x][y] = '0';
        int dirx[4] = {-1,0,1,0}, diry[4] = {0,1,0,-1};
        for(int i = 0; i < 4; i++) {
            int nx = dirx[i] + x;
            int ny = diry[i] + y;
            dfs(grid,nx,ny);
        }
    }
};
