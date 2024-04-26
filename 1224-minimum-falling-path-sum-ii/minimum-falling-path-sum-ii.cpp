class Solution {
public:
    int f(int row, int col, vector<vector<int>> &grid, int n, vector<vector<int>> &dp){
        if(row < 0 or col < 0 or row >= n or col >= n)return 1e9;
        if(row == n-1)return grid[row][col];

        if(dp[row][col] != -1e8)return dp[row][col];

        int minsum = 1e9;
        for(int k=0;k<n;k++){
                int sum = grid[row][col];
            if(k != col){
                sum += f(row+1,k,grid,n,dp);
                minsum = min(minsum,sum);
                // minsum = min(minsum,grid[row][col]+f(row+1,k,grid,n));
            }
        }
        return dp[row][col] = minsum;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1e8));
        int mini = 1e9;
        for(int j=0;j<n;j++){
            int sum = f(0,j,grid,n,dp);
            mini = min(mini,sum);
        }
        return mini;
    }
};