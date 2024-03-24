class Solution {
public:
    typedef pair<int,pair<int,int>> pp;
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1)return -1;
        int delrow[] = {0,-1,-1,-1,0,1,1,1}; 
        int delcol[] = {1,1,0,-1,-1,-1,0,1};
        priority_queue<pp,vector<pp>,greater<pp>> pq;
        pq.push({1,{0,0}});
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        dist[0][0] = 1;
        while(!pq.empty()){
            int distance = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            for(int i=0;i<8;i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow>=0 && ncol>=0 && nrow<n && ncol<n && grid[nrow][ncol] == 0){
                    if(dist[nrow][ncol] > 1 + distance){
                        dist[nrow][ncol] = 1 + distance;
                        pq.push({dist[nrow][ncol],{nrow,ncol}});
                    }
                }
            }
        }

        if(dist[n-1][n-1] == 1e9)return -1;
        return dist[n-1][n-1];
    }
};