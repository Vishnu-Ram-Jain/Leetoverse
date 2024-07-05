class Solution {
public:
    int delrow[4] = {0,1,0,-1};
    int delcol[4] = {1,0,-1,0};
    int cnt = 0;
    void f(int row, int col, vector<vector<int>> &mat1, vector<vector<int>> &mat2,
    vector<vector<int>> &vis, int n, int m, bool &flag){
        vis[row][col] = 1;
        if(mat1[row][col] == 0)flag = false;
        for(int i=0;i<4;i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && mat2[nrow][ncol] == 1 && !vis[nrow][ncol]){
                f(nrow,ncol,mat1,mat2,vis,n,m,flag);
            }
        }
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m = grid1[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid2[i][j] == 1 && !vis[i][j]){
                    bool fl = true;
                    f(i,j,grid1,grid2,vis,n,m,fl);
                    if(fl)cnt++;
                }
            }
        }
        return cnt;
    }
};