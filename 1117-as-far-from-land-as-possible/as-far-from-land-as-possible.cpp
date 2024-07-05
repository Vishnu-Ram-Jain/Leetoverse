class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int,pair<int,int>>> q;
        int n = grid.size();
        vector<vector<int>> vis(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    vis[i][j] = 1;
                    q.push({0,{i,j}});
                }
            }
        }
        int delrow[4] = {0,1,0,-1};
        int delcol[4] = {1,0,-1,0};
        int maxi = -1;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int dist = it.first;
            int row = it.second.first;
            int col = it.second.second;
            maxi = max(maxi,dist);
            for(int i=0;i<4;i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow>=0 && ncol>=0 && nrow<n && ncol<n && !vis[nrow][ncol]){
                    vis[nrow][ncol] = 1;
                    // int newdist = abs(nrow-row) + abs(ncol-col);
                    q.push({1 + dist,{nrow,ncol}});
                }
            }
        }
        return maxi == 0 ? -1 : maxi;
    }
};