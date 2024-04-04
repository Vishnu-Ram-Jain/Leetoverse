class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        queue<pair<int,int>> q;
        vector<int> adj[n];

        for(int i=0;i<n;i++){
            if(manager[i] != -1)adj[manager[i]].push_back(i);
        }

        vector<int> vis(n,0);
        q.push({0,headID});
        vis[headID] = 1;
        int tm = 0;
        while(!q.empty()){
            int time = q.front().first;
            int node = q.front().second;
            q.pop();
            tm = max(tm,time);
            for(auto it : adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push({informTime[node] + time,it});
                }
            }
        }
        return tm;
    }
};