class Solution {
public:
    typedef pair<int,pair<int,int>> pp;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto it : flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int> dist(n,1e9);

        dist[src] = 0;
        priority_queue<pp,vector<pp>,greater<pp>> pq;
        pq.push({0,{0,src}});
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int stops = it.first;
            int dis = it.second.first;
            int node = it.second.second;

            if(stops > k)continue;

            for(auto i : adj[node]){
                int adjnode = i.first;
                int edgewt = i.second;

                if(dist[adjnode] > dis + edgewt){
                    dist[adjnode] = dis + edgewt;
                    pq.push({1+stops,{dist[adjnode],adjnode}});
                }
            }

        }

        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};