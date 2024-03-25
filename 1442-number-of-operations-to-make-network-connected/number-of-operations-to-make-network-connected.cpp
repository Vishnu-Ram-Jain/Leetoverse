class Solution {
public:
    void dfs(int snode, vector<int> &vis, vector<int> adj[]){
        vis[snode] = 1;

        for(auto it : adj[snode]){
            if(!vis[it]){
                dfs(it,vis,adj);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& c) {
        int totedges = c.size();
        if(totedges < n - 1)return -1;
        vector<int> vis(n,0);
        vector<int> adj[n+1];
        for(auto it : c){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int count = 0;

        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,adj);
                count++;
            }
        }

        return count - 1;
    }
};