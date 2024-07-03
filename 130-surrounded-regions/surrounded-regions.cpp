class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>& b,vector<vector<int>>&vis,int n,int m){
        vis[i][j]=1;
        int dr[4]={-1,0,1,0};
        int dc[4]={0,1,0,-1};
        for(int k=0;k<4;k++){
            int nr=i+dr[k];
            int nc=j+dc[k];
            if(nr>=0 && nc>=0 && nc<m && nr<n && vis[nr][nc]!=1 && b[nr][nc]=='O'){
                dfs(nr,nc,b,vis,n,m);
            }
        }
    }
    void solve(vector<vector<char>>& b) {
        vector<pair<int,int>>p;
        int n=b.size();
        int m=b[0].size();
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<m;i++)
        {
            if( !vis[0][i] && b[0][i]=='O')
                dfs(0,i,b,vis,n,m);
            if(!vis[n-1][i] && b[n-1][i]=='O')
                dfs(n-1,i,b,vis,n,m);
        }
        for(int i=0;i<n;i++){
            if(!vis[i][m-1]&& b[i][m-1]=='O'){
                dfs(i,m-1,b,vis,n,m);
            }
            if(!vis[i][0] && b[i][0]=='O'){
                dfs(i,0,b,vis,n,m);
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && b[i][j] == 'O' )
                    b[i][j]='X';
            }
        }
    }
};