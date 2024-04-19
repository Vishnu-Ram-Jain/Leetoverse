class Solution {
public:

    void dfs(vector<vector<int>> &vis, int row, int col, vector<vector<char>>& grid){
        int n = grid.size(); 
        int m = grid[0].size();
        vis[row][col] = 1;
    
        int delrow[] = {0,1,0,-1};
        int delcol[] = {1,0,-1,0};

        for(int i=0;i<4;i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol] == '1'
            && !vis[nrow][ncol]){
                dfs(vis,nrow,ncol,grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(); 
        int m = grid[0].size();
        int count = 0; 
        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(grid[i][j] == '1' && !vis[i][j]){
                    dfs(vis,i,j,grid);
                    count++;
                }
            }
        }
        return count;
    }
};