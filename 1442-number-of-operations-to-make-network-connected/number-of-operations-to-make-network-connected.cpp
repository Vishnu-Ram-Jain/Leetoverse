class DisjointSet{
    vector<int> parent,rank;
    public:

    DisjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);

        for(int i=0;i<=n;i++){
            parent[i] = i;
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
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        // int totedge = connections.size();
        // if(totedge < n-1)return -1;
        int extraedges = 0;
        for(auto it : connections){
            int u = it[0];
            int v = it[1];

            int pu = ds.findUPar(u);
            int pv = ds.findUPar(v);

            if(pu != pv){
                ds.union_by_rank(u,v);
            }
            else{
                extraedges++;
            }
        }
        int count = 0;
        for(int i=0;i<n;i++){
            if(ds.findUPar(i) == i)count++;
        }

        return extraedges >= count-1 ? count-1 : -1;
    }
};