class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<pair<int,int>,int>> q;
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> v(n,vector<int>(m,0));
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    vis[i][j] = 1;
                    q.push({{i,j},0});
                }
            }
        }
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dist = q.front().second;
            q.pop();
            v[row][col] = dist;
            for(int i=0;i<4;i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if(nrow>=0 && ncol>=0 && ncol<m && nrow<n && !vis[nrow][ncol]
                && mat[nrow][ncol] == 1){
                    vis[nrow][ncol] = 1;
                    q.push({{nrow,ncol},1+dist});    
                }
            }
        }

        return v;
    }
};