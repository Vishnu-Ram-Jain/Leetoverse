class Solution {
public:
    void dfs(vector<int> adj[], int node, vector<int>& vis){
        vis[node] = 1;

        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(adj,it,vis);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<rooms[i].size();j++){
                adj[i].push_back(rooms[i][j]);
            }
        }
        vector<int> vis(n,0);
        dfs(adj,0,vis);
        for(int i=0;i<n;i++){
            if(vis[i] == 0)return false;
        }
        return true;
    }
};