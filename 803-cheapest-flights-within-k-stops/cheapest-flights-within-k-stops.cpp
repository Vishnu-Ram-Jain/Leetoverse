class Solution {
public:
    typedef pair<int,pair<int,int>> pp;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
       vector<pair<int,int>> adj[n+1];

        for (auto it : flights)
        {
            adj[it[0]].push_back({it[1], it[2]});
        }

        vector<int> dist(n,1e9);
        dist[src] = 0;

        priority_queue<pp,vector<pp>,greater<pp>> pq;
        pq.push({0,{0,src}});

        while(!pq.empty()){
            int stops = pq.top().first;
            int wt = pq.top().second.first;
            int node = pq.top().second.second;
            pq.pop();

            if(stops > k)continue;


            for(auto it : adj[node]){
                int adjnode = it.first;
                int edgewt = it.second;

                if(dist[adjnode] > wt + edgewt){
                    dist[adjnode] = wt + edgewt;
                    pq.push({1+stops,{dist[adjnode],adjnode}});
                }

            }
        }

        return dist[dst] == 1e9 ? -1 : dist[dst];

    }
};