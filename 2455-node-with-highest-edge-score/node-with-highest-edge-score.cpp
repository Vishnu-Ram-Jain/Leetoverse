class Solution {
public:
    typedef long long ll;
    int edgeScore(vector<int>& edge) {
        int n = edge.size();
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            adj[edge[i]].push_back(i);
        }
        ll maxi = 0;
        int node = -1;
        for(int i=0;i<n;i++){
            ll sum = 0;
            for(auto it : adj[i]){
                sum += it;
            }
            if(maxi < sum){
                maxi = sum;
                node = i;
            }
        }
        return node;

    }
};