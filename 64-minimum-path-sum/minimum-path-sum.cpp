class Solution {
public:
    int dp[201][201];
    int f(int i, int j, vector<vector<int>> &grid, int n, int m){
        if(i>=n or j>=m or i<0 or j<0)return 1e9;
        if(i == n-1 && j == m-1)return grid[i][j];

        if(dp[i][j] != -1)return dp[i][j];

        int op1 = grid[i][j] + f(i+1,j,grid,n,m);
        int op2 = grid[i][j] + f(i,j+1,grid,n,m);

        return dp[i][j] = min(op1,op2);
    }
    int minPathSum(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        int n = grid.size();
        int m = grid[0].size();
        return f(0,0,grid,n,m);
    }
};