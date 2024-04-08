class Solution {
public:
    int mod = 1e9 + 7;
    int dfs(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp, int n, int m, int prev){
        if(i<0 or j<0 or i>=n or j>=m or grid[i][j] <= prev)return 0;

        if(dp[i][j] != -1)return dp[i][j];

        int a = 1 + dfs(i,j+1,grid,dp,n,m,grid[i][j]);
        int b = 0 + dfs(i-1,j,grid,dp,n,m,grid[i][j]);
        int c = 0 + dfs(i,j-1,grid,dp,n,m,grid[i][j]);
        int d = 0 + dfs(i+1,j,grid,dp,n,m,grid[i][j]);

        return dp[i][j] = (a+b+c+d) % mod;
    }
    int countPaths(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans = (ans + dfs(i,j,grid,dp,n,m,-1)) % mod;
            }
        }
        return ans % mod;
    }
};