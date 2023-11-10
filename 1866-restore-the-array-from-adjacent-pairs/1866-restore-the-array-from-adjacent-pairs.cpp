class Solution {
public:
    void f(unordered_map<int,vector<int>> &mp, vector<int> &v, int node, map<int,bool> &vis){
        vis[node] = 1;
        v.push_back(node);

        for(auto it : mp[node]){
            if(!vis[it]){
                f(mp,v,it,vis);
            }
        }
    }
    vector<int> restoreArray(vector<vector<int>>& a) {
        map<int,int> m;
        unordered_map<int,vector<int>> mp;
        int n = a.size();
        map<int,bool> vis;
        vector<int> adj[n+1];
        for(int i=0;i<n;i++){
            m[a[i][0]]++;
            m[a[i][1]]++;
            mp[a[i][0]].push_back(a[i][1]);
            mp[a[i][1]].push_back(a[i][0]);
            vis[a[i][0]] = 0;
            vis[a[i][1]] = 0;
        }

        int num = -1;
        for(auto it: m){
            if(it.second == 1){
                num = it.first;
                break;
            }
        }

        vector<int> v;
        f(mp,v,num,vis);
        return v;
    }
};