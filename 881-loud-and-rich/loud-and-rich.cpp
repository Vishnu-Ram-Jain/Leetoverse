class Solution {
public:
    void dfs(int node, vector<int> &op, vector<int> adj[], vector<int> &vis){
        op.push_back(node);
        vis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it,op,adj,vis);
            }
        }
    }
    vector<int> loudAndRich(vector<vector<int>>& r, vector<int>& q) {
        int n = q.size();
        vector<int> adj[n];
        for (auto vec : r) {
            adj[vec[1]].push_back(vec[0]);
        }
        vector<int> ans(n,1e8);
        for(int i=0;i<n;i++){
            vector<int> vis(n+1,0);
            vector<int> op;
        
            dfs(i,op,adj,vis);
            int val = 1e9;
            for(int j=0;j<op.size();j++){
                // cout<<op[j]<<" ";
                if(val >= q[op[j]]){
                    val = q[op[j]];
                    ans[i] = op[j];
                } 
            }
                // cout<<endl;
        }
        return ans;
    }
};