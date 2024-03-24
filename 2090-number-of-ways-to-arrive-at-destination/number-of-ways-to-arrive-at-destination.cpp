class Solution {
public:
    int mod = 1e9+7;
    typedef long long ll;
    int countPaths(int n, vector<vector<int>>& t) {
        ll k = 0;
        vector<pair<ll,ll>> adj[n+1];
        for(int i=0;i<t.size();i++){
            adj[t[i][0]].push_back({t[i][1],t[i][2]});
            adj[t[i][1]].push_back({t[i][0],t[i][2]});
        }
        vector<ll> dist(n,LLONG_MAX);
        vector<ll> ways(n,0);
        dist[k] = 0;
        ways[k] = 1;
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
        pq.push({0,k});
        
        while(!pq.empty()){
            ll node = pq.top().second;
            ll distance = pq.top().first;
            pq.pop();
            
            for(auto it : adj[node]){
                ll edgewt = it.second;
                ll adjnode = it.first;
                
                if(dist[adjnode] > edgewt + distance){
                    dist[adjnode] = edgewt + distance;
                    pq.push({dist[adjnode],adjnode});
                    ways[adjnode] = ways[node];
                }
                else if(dist[adjnode] == edgewt + distance){
                    ways[adjnode] = (ways[adjnode] + ways[node]) % mod;
                }
            }
        }
        return ways[n-1] % mod;
    }
};