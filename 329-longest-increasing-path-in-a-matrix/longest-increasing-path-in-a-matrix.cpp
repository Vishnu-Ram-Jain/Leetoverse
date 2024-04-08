class Solution {
public:
    int delrow[4] = {0,1,0,-1};
    int delcol[4] = {1,0,-1,0};
    int dfs(int n, int m, int row, int col, vector<vector<int>> &mat, int prev,vector<vector<int>> &dp){
        if(mat[row][col] <= prev)return 0;

        if(dp[row][col] != -1)return dp[row][col];

        int steps = 0;

        for(int i=0;i<4;i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow>=0 && ncol>=0 && ncol<m && nrow<n){
                steps = max(steps,1+dfs(n,m,nrow,ncol,mat,mat[row][col],dp));
            }
        }
        return dp[row][col] = steps;
    }
    int longestIncreasingPath(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();
        if(n==1 && m==1)return 1;
        int maxlen = 0;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int len = dfs(n,m,i,j,mat,-1,dp);
                maxlen = max(maxlen,len);
            }
        }
        return maxlen;

    }
};