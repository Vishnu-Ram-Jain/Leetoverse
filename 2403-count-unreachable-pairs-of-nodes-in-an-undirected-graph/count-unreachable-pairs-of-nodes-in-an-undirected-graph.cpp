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
    typedef long long ll;
    long long countPairs(int n, vector<vector<int>>& edges) {
        DisjointSet ds(n);

        for(auto it : edges){
            if(ds.findUPar(it[0]) != ds.findUPar(it[1])){
                ds.union_by_size(it[0],it[1]);
            }
        }
        vector<ll> v;
        for(int i=0;i<n;i++){
            if(ds.findUPar(i) == i){
                if(ds.size[i] > 1)v.push_back(ds.size[i]);
            }
        }
        ll cnt = (ll)n*(n-1)/2;
        for(int i=0;i<v.size();i++){
            ll val = v[i];
            val = val*(val-1)/2;
            cnt -= val;

        }
        return cnt;
    }
};