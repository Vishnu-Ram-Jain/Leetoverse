class DisjointSet {
    vector<int> rank, parent;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& arr) {
        int n = arr.size();
        DisjointSet ds(n);
        unordered_map<string,int> mp;

        for(int i=0;i<n;i++){
            for(int j=1;j<arr[i].size();j++){
                string mail = arr[i][j];
                if(mp.find(mail) == mp.end()){
                    mp[mail] = i;
                }
                else{
                    ds.unionByRank(i,mp[mail]);
                }
            }
        }

        vector<string> mailmerge[n];

        for(auto it : mp){
            string mail = it.first;
            int node = ds.findUPar(it.second);
            mailmerge[node].push_back(mail);
        }

        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(mailmerge[i].size()==0)continue;
            sort(mailmerge[i].begin(),mailmerge[i].end());
            vector<string> temp;
            temp.push_back(arr[i][0]);
            for(auto it : mailmerge[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};