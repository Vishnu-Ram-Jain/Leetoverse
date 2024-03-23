class Solution {
public:
    bool dfs(vector<int> adj[], vector<bool> &vis, int node, int parent){
        vis[node] = 1;
        
        for(auto it : adj[node]){
            if(!vis[it]){
                if(dfs(adj,vis,it,node))return true;
            }
            else{
                if(parent != it)return true;
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> adj[n+1];

        for(int i=0;i<n;i++){
            int a = edges[i][0];
            int b = edges[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
            vector<bool> vis(n+1,0);
            if(dfs(adj,vis,edges[i][0],-1))return edges[i];
        }
        return {};
    }
};