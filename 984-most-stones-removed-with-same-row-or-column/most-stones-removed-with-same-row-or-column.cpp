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
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxrow = 0;
        int maxcol = 0;

        for(auto it : stones){
            maxrow = max(maxrow,it[0]);
            maxcol = max(maxcol,it[1]);
        }
        DisjointSet ds(maxrow + maxcol + 1);
        unordered_map<int,int> mp;
        for(auto it : stones){
            int u = it[0];
            int v = it[1] + maxrow + 1;
            ds.union_by_size(u,v);
            mp[u] = 1;
            mp[v] = 1;
        }

        int cnt = 0;

        for(auto it : mp){
            if(it.first == ds.findUPar(it.first))cnt++;
        }

        return n - cnt;

    }
};