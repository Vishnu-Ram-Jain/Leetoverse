class Solution {
public:
        int delrow[4] = {0,1,0,-1};
        int delcol[4] = {1,0,-1,0};
    int dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis, int n, int m){
        vis[row][col] = 1;

        int temp = grid[row][col];

        for(int i=0;i<4;i++){
            int nrow = row + delrow[i]; 
            int ncol = col + delcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m 
                && grid[nrow][ncol] > 0 && !vis[nrow][ncol]){
                    temp += dfs(nrow,ncol,grid,vis,n,m);
            }
        }
        return temp;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxi = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] > 0){
                    vector<vector<int>> vis(n,vector<int>(m,0));
                    maxi = max(maxi,dfs(i,j,grid,vis,n,m));
                }
            }
        }
        return maxi;
    }
};