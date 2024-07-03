class Solution {
public:
    int delrow[4]={-1,0,1,0};
    int delcol[4]={0,1,0,-1};
    void f(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid, int n, int m){
        vis[row][col] = 1;

        for(int i=0;i<4;i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol] == 1){
                f(nrow,ncol,vis,grid,n,m);
            }
        }

    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            if(!vis[0][i] && grid[0][i] == 1){
                f(0,i,vis,grid,n,m);
            }
        }
        for(int i=0;i<m;i++){
            if(!vis[n-1][i] && grid[n-1][i] == 1){
                f(n-1,i,vis,grid,n,m);
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i][0] && grid[i][0] == 1){
                f(i,0,vis,grid,n,m);
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i][m-1] && grid[i][m-1] == 1){
                f(i,m-1,vis,grid,n,m);
            }
        }

        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j] == 0 && grid[i][j] == 1)cnt++;
            }
        }
        return cnt;
    }
};