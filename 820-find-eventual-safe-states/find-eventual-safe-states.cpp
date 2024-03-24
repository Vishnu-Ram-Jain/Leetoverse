class Solution {
public:
    bool dfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &pathvis,
    vector<int> &check){
        vis[node] = 1;
        pathvis[node] = 1;
        check[node] = 1;

        for(auto it : adj[node]){
            if(!vis[it]){
                if(dfs(it,vis,adj,pathvis,check))return true;
            }
            else{
                if(pathvis[it])return true;
            }
        }
        pathvis[node] = 0;
        check[node] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> adj[n+1];
        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                adj[i].push_back(graph[i][j]);
            }
        }
        vector<int> vis(n,0);
        vector<int> pathvis(n,0);
        vector<int> check(n,0);

        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,adj,pathvis,check);
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(check[i] == 0)ans.push_back(i);
        }
        return ans;
    }
}; 