/*695：给定一个包含了一些 0 和 1 的非空二维数组?grid 。
一个?岛屿?是由一些相邻的?1?(代表土地) 构成的组合，这里的「相邻」要求两个 1 必须在水平或者竖直方向上相邻。你可以假设?grid 的四个边缘都被 0（代表水）包围着。
找到给定的二维数组中最大的岛屿面积。(如果没有岛屿，则返回面积为 0 。)
*/
class Solution {
    int dirx[4] = {-1,0,1,0},diry[4] = {0,1,0,-1};
    
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                 ans = max(dfs(grid,i,j),ans);
            }
        }
        return ans;
    }
    int dfs(vector<vector<int>>& grid,int x,int y) {
        if(x < 0 || y < 0 || x == grid.size() || y == grid[0].size() || grid[x][y] == 0) {
            return 0;
        }
        grid[x][y] = 0;
        int ans = 1;
        for(int i = 0; i < 4; i++) {
            int nx = x + dirx[i];
            int ny = y + diry[i];
            ans += dfs(grid,nx,ny);
        }
        return ans;
    }
};
