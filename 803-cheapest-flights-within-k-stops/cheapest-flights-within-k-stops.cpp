class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& f, int src, int dst, int k) {
        vector<pair<int,int>> adj[n+1];

        for (auto it : f)
        {
            adj[it[0]].push_back({it[1], it[2]});
        }

        // for(int i=0;i<n;i++){
        //     adj[f[i][0]].push_back({f[i][1],f[i][2]});
        // }

        queue<pair<int,pair<int,int>>> q;
        // stops,node,dist;
        q.push({0,{src,0}});
        vector<int> dist(n,1e9);
        dist[src] = 0;
        while(!q.empty()){
            int stops = q.front().first;
            int node = q.front().second.first;
            int distance = q.front().second.second;
            q.pop();

            if(stops > k)continue;

            for(auto it : adj[node]){
                int adjnode = it.first;
                int wt = it.second;

                if(dist[adjnode] > distance + wt && stops <= k){
                    dist[adjnode] = distance + wt;
                    q.push({stops+1,{adjnode,distance + wt}});
                }
            }
        }
        

        if(dist[dst] == 1e9)return -1;
        return dist[dst];

    }
};