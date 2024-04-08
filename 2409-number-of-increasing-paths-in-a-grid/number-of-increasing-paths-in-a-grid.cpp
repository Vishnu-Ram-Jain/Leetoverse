class Solution {
public:
    int mod = 1e9 + 7;
    int delrow[4] = {0,1,0,-1};
    int delcol[4] = {1,0,-1,0};
    int dfs(int n, int m, int row, int col, vector<vector<int>> &mat, int prev,vector<vector<int>> &dp){
        if(mat[row][col] <= prev)return 0;

        if(dp[row][col] != -1)return dp[row][col];

        int steps = 1;

        for(int i=0;i<4;i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow>=0 && ncol>=0 && ncol<m && nrow<n){
                steps += dfs(n,m,nrow,ncol,mat,mat[row][col],dp);
            }
        }
        return dp[row][col] = steps % mod;
    }
    int countPaths(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans = (ans + dfs(n,m,i,j,grid,-1,dp)) % mod;
            }
        }
        return ans % mod;
    }
};