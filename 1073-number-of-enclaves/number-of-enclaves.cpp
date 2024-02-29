class Solution {
public:
    int numEnclaves(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            if(mat[0][i]==1){
                q.push({0,i});
                vis[0][i] = 1;
            }
        }
        for(int i=0;i<m;i++){
            if(mat[n-1][i]==1){
                q.push({n-1,i});
                vis[n-1][i] = 1;
            }
        }
        for(int i=0;i<n;i++){
            if(mat[i][0]==1){
                q.push({i,0});
                vis[i][0] = 1;
            }
        }
        for(int i=0;i<n;i++){
            if(mat[i][m-1]==1){
                q.push({i,m-1});
                vis[i][m-1] = 1;
            }
        }

        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && mat[nrow][ncol]==1 && !vis[nrow][ncol]){
                    vis[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                }
            }
        }
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 1 && !vis[i][j])cnt++;
            }
        }
        return cnt;
    }
};