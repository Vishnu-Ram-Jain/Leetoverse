class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& m, vector<int>& informTime) {
        vector<int> adj[n];
        int sz = m.size();
        for(int i=0;i<sz;i++){
            if(m[i] != -1)adj[m[i]].push_back(i);
        }

        queue<pair<int,int>> q;
        q.push({0,headID});
        int tm = 0;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int node = it.second;
            int time = it.first;
            tm = max(tm,time);

            for(auto &it : adj[node]){
                int edgewt = informTime[node];
                q.push({time+edgewt,it});
            }
        }
        return tm;
    }
};