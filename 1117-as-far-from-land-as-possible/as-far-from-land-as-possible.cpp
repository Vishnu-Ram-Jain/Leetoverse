class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int,pair<int,int>>> q;
        int n = grid.size();

        vector<vector<bool>> vis(n,vector<bool>(n,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    vis[i][j] = 1;
                    q.push({0,{i,j}});
                }
            }
        }
        int delrow[] = {0,1,0,-1};
        int delcol[] = {1,0,-1,0};
        int maxi = 0;
        while(!q.empty()){
            int dist = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            // cout<<dist<<endl;
            maxi = max(maxi,dist);

            for(int i=0;i<4;i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow>=0 && ncol>=0 && nrow<n && ncol<n && !vis[nrow][ncol] 
                && grid[nrow][ncol] == 0){
                    vis[nrow][ncol] = 1;
                    q.push({1+dist,{nrow,ncol}});
                }
            }
        }
        return maxi == 0 ? -1 : maxi;
    }
};