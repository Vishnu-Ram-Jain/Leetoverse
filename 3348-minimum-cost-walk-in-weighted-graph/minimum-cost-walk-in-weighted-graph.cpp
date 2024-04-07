class DisjointSet{

    public:
    vector<int> parent,rank,size;

    DisjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        size.resize(n+1,0);

        for(int i=0;i<=n;i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node){
        if(node == parent[node])return node;

        return parent[node] = findUPar(parent[node]);
    }

    void union_by_rank(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v)return;

        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void union_by_size(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v)return;

        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        DisjointSet ds(n);

        for(auto &it : edges){
            int u = it[0];
            int v = it[1];
            int pu = ds.findUPar(u);
            int pv = ds.findUPar(v);
            if(pu != pv)ds.union_by_size(u,v);
        }

        unordered_map<int,int> mp;

        for(auto &it : edges){
            int u = ds.findUPar(it[0]);

            if(mp.find(u) == mp.end()){
                mp[u] = it[2];
            }
            else{
                mp[u] &= it[2];
            }
        }
        vector<int> ans;
        for(auto &it : query){
            int u = it[0];
            int v = it[1];

            if(u == v)ans.push_back(0);
            else if(ds.findUPar(u) != ds.findUPar(v))ans.push_back(-1);
            else{
                ans.push_back(mp[ds.findUPar(u)]);
            }
        }
        return ans;
    }
};