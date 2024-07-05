class Solution {
public:
    int mod = 1e9 + 7;
    int dp[5][4][5002];
    int delrow[8] = {2, 2, -2, -2, 1, 1, -1, -1};
    int delcol[8] = {1, -1, 1, -1, 2, -2, 2, -2};

    int f(int row, int col, vector<vector<int>> &mat, int steps){
        if(mat[row][col] == 11)return 0;
        if(steps == 0)return 1;
        if(dp[row][col][steps] != -1)return dp[row][col][steps];
        int ans = 0;
        for(int i=0;i<8;i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow>=0 && ncol>=0 && nrow<4 && ncol<3){
                ans = (ans + f(nrow,ncol,mat,steps-1)) % mod;
            }
        }
        return dp[row][col][steps] = ans % mod;
    }
    int knightDialer(int n) {
        vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9},{11,0,11}};
        memset(dp,-1,sizeof(dp));
        int ans = 0;
        for(int i=0;i<4;i++){
            for(int j=0;j<3;j++){
                if(mat[i][j] != 11)ans = (ans + f(i,j,mat,n-1)) % mod;
            }
        }
        return ans;
    }
};