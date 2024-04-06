class Solution {
public:
    typedef pair<double,string> pp;
    double f(string &src, unordered_map<string,vector<pair<double,string>>> &adj, string &dst){
        if(adj.find(src) == adj.end() || adj.find(dst) == adj.end())return -1.0;
        
        priority_queue<pp,vector<pp>,greater<pp>> pq;
        pq.push({(double)1,src});

        unordered_map<string,bool> vis;
        vis[src] = 1;

        while(!pq.empty()){
            string node = pq.top().second;
            double dis = pq.top().first;
            pq.pop();
            if(node == dst)return dis;
            for(auto it : adj[node]){
                double edgewt = it.first;
                string adjnode = it.second;

                if(vis.find(adjnode) == vis.end()){
                    vis[adjnode] = 1;
                    pq.push({(double)dis*edgewt,adjnode});
                }
            }
        }
        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations,
                            vector<double>& values, vector<vector<string>>& queries) {

        unordered_map<string,vector<pair<double,string>>> adj;
        int n = equations.size();

        for(int i=0;i<n;i++){
            string u = equations[i][1];
            string v = equations[i][0];
            double wt = values[i];
            adj[u].push_back({(double)wt,v});
            adj[v].push_back({(double)1/wt,u});
        }

        vector<double> ans;
        for(int i=0;i<queries.size();i++){
            string src = queries[i][1];
            string dst = queries[i][0];
            double dist = f(src,adj,dst);
            ans.push_back(dist);
        }
        return ans;
    }
};