/*695������һ��������һЩ 0 �� 1 �ķǿն�ά����?grid ��
һ��?����?����һЩ���ڵ�?1?(��������) ���ɵ���ϣ�����ġ����ڡ�Ҫ������ 1 ������ˮƽ������ֱ���������ڡ�����Լ���?grid ���ĸ���Ե���� 0������ˮ����Χ�š�
�ҵ������Ķ�ά���������ĵ��������(���û�е��죬�򷵻����Ϊ 0 ��)
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
