class Solution {
public:
    typedef pair<int,int> pp;
    int f(int n, vector<pair<int,int>> adj[], int k, int src){
        vector<int> dist(n,1e9);
        dist[src] = 0;
        priority_queue<pp,vector<pp>,greater<pp>> pq;
        pq.push({0,src});

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int dis = it.first;

            for(auto &i : adj[node]){
                int adjnode = i.first;
                int edgewt = i.second;
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

        int city = n;
        int temp = n;
        for(int i=0;i<n;i++){
            int cnt = f(n,adj,distanceThreshold,i);
            if(cnt <= temp){
                city = i;
                temp = cnt;
            }
        }
        return city;
    }
};