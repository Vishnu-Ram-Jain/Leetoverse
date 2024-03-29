class Solution {
public:
    int dfs(vector<vector<int>> &grid, vector<vector<int>> &vis, int row, int col, int &cnt){
        int n = grid.size(); 
        int m = grid[0].size();
        vis[row][col] = 1;
        // cnt++;
        int delrow[] = {0,1,0,-1};
        int delcol[] = {1,0,-1,0};
        int count = 1;
        for(int i=0;i<4;i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
                grid[nrow][ncol] == 1 && !vis[nrow][ncol]){
                    // cnt++;
                    count += dfs(grid,vis,nrow,ncol,cnt);
                }
        }
        return count;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(); 
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int maxi = -1;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    int temp = 0;
                    // dfs(grid,vis,i,j,temp);
                    // cout<<temp<<endl;
                    maxi = max(maxi,dfs(grid,vis,i,j,temp));
                }
            }
        }
        return maxi == -1 ? 0 : maxi;       
    }
};