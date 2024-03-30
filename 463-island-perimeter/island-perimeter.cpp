class Solution {
public:
        int delrow[4] = {0,1,0,-1};
        int delcol[4] = {1,0,-1,0};
    int dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis,int n, int m){
        if(row>=n or col>=m or row<0 or col<0 or grid[row][col] == 0)return 1;
        if( vis[row][col] == 1)return 0;
        vis[row][col] = 1;
        int cnt = 0;
        for(int i=0;i<4;i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            cnt += dfs(nrow,ncol,grid,vis,n,m);
          
        }
        return cnt;
    }
    int islandPerimeter(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int per = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1 &&!vis[i][j]){
                    per = dfs(i,j,grid,vis,n,m);
                    break;
                }
            }
        }
        return per;
    }
};