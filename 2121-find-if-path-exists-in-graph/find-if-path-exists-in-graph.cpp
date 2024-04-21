class Solution {
public:
    bool dfs(int source, int destination, vector<int> adj[], vector<int>& vis){
        vis[source] = 1;
        if(source == destination)return true;

        for(auto it : adj[source]){
            if(!vis[it]){
                if(dfs(it,destination,adj,vis))return true;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> adj[n+1];
        vector<int> vis(n+1,0);
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return (dfs(source,destination,adj,vis));
    }
};