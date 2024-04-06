class Solution {
public:
    typedef pair<int,int> pp;
    int f(int n, int src, vector<pair<int,int>> adj[], int k){
        vector<int> dist(n,1e9);
        dist[src] = 0;

        priority_queue<pp,vector<pp>,greater<pp>> pq;
        pq.push({0,src});

        while(!pq.empty()){
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();
            for(auto it : adj[node]){
                int adjnode = it.first;
                int edgewt = it.second;

                if(dis + edgewt < dist[adjnode]){
                    dist[adjnode] = dis + edgewt;
                    pq.push({dist[adjnode],adjnode});
                }
            }
        }
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(dist[i] != 1e9 && dist[i] <= k)cnt++;
        }
        return cnt;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<pair<int,int>> adj[n];
        for(auto &it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        int mincnt = 1e9;
        int city = -1;
        for(int i=0;i<n;i++){
            int cnt = f(n,i,adj,distanceThreshold);
            if(mincnt >= cnt){
                mincnt = cnt;
                city = i;
            }
        }
        return city;
    }
};