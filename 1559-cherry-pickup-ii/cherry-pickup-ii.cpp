class Solution {
public:
    int f(int i, int j1, int j2, vector<vector<vector<int>>> &dp, vector<vector<int>>& grid, int n, int m){
        // 
        if(j1 < 0 or j2 < 0 or j1 >= m or j2 >= m)return -1e8;
        if(i == n-1){
            if(j1 == j2)return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }
        
        if(dp[i][j1][j2] != -1)return dp[i][j1][j2];
        
        int maxi = 0;
        for(int ind=-1;ind<=1;ind++){
            for(int j=-1;j<=1;j++){
                int temp = ((j1 == j2) ? grid[i][j1] : grid[i][j1] + grid[i][j2])+  f(i+1,j1+ind,j2+j,dp,grid,n,m);
                maxi = max(maxi,temp);
            }
        }
        
        return dp[i][j1][j2] = maxi;
        
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(m+1,vector<int>(m+1,-1)));
        return f(0,0,m-1,dp,grid,n,m);
    }
};