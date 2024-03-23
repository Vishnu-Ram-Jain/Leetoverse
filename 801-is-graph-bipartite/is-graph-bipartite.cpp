class Solution {
public:
    bool bfs(vector<int> adj[], vector<bool> &vis, int snode, vector<int> &col){
        queue<int> q;
        q.push(snode);
        col[snode] = 0;
        vis[snode] = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it : adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    col[it] = !col[node];
                    q.push(it);
                }
                else{
                    if(col[it] == col[node])return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> adj[n+1];
        vector<int> col(n+1);
        for(int i=0;i<n;i++){
            for(int j=0;j<edges[i].size();j++){
                adj[i].push_back(edges[i][j]);
            }
        }
        vector<bool> vis(n+1,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(bfs(adj,vis,i,col) == false)return false;
            }
        }
        return true;
    }
};