class Solution {
public:
    typedef pair<int,pair<int,int>> pp;
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1)return -1;
        vector<vector<int>> vis(n,vector<int>(n,0));
        priority_queue<pp,vector<pp>,greater<pp>> pq;
        pq.push({1,{0,0}});
        vis[0][0] = 1;

        int delrow[] = {0,-1,-1,-1,0,1,1,1}; 
        int delcol[] = {1,1,0,-1,-1,-1,0,1};

        while(!pq.empty()){
            int dist = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            if(row == n-1 && col == n-1)return dist;
            for(int i=0;i<8;i++){
                int nr = row + delrow[i];
                int nc = col + delcol[i];

                if(nr>=0 && nc>=0 && nc<n && nr<n && grid[nr][nc] == 0 && !vis[nr][nc]){
                    pq.push({1+dist,{nr,nc}});
                    vis[nr][nc] = 1;
                }
            }

        }
        return -1;
    }
};