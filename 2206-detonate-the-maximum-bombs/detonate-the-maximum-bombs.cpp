class Solution {
public:
    void dfs(int node, vector<int> &vis, vector<int> adj[], int &cnt){
        vis[node] = 1;
        cnt++;
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it,vis,adj,cnt);
            }
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            long long x=bombs[i][0];
            long long y=bombs[i][1];
            long long r=bombs[i][2];
            for(int j=0;j<n;j++){
                if(i!=j){
                    long long x1=abs(x-bombs[j][0]);
                    long long y1=abs(y-bombs[j][1]);
                    if(x1*x1+y1*y1<=r*r){
                        adj[i].push_back(j);
                    }
                }
            }
        }

        int maxcnt = 0;
        for(int i=0;i<n;i++){
            vector<int> vis(n,0);
            int cnt = 0;
            dfs(i,vis,adj,cnt);
            maxcnt = max(maxcnt,cnt);
            
        }
        return maxcnt;
    }
};