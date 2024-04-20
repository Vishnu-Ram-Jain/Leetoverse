class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &mat,
        int &mxr, int &mxc, int n, int m){
            vis[row][col] = 1;
            mxr = max(mxr,row);
            mxc = max(mxc,col);
            for(int i=0;i<4;i++){
                int nrow = row + dx[i];
                int ncol = col + dy[i];
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !vis[nrow][ncol] && mat[nrow][ncol] == 1){
                    dfs(nrow,ncol,vis,mat,mxr,mxc,n,m);
                }
            }
        }
    vector<vector<int>> findFarmland(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 1 && !vis[i][j]){
                    int mxr = -1, mxc = -1;
                    dfs(i,j,vis,mat,mxr,mxc,n,m);
                    ans.push_back({i,j,mxr,mxc});
                }
            }
        }
        return ans;
    }
};