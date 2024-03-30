class Solution {
public:
    typedef pair<int,int> pp;
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int,pp> mp;
        unordered_map<int,int> row;
        unordered_map<int,int> col;
        int n = mat.size();
        int m = mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mp[mat[i][j]] = {i,j};
            }
        }

        for(int i=0;i<arr.size();i++){
            int val = arr[i];
            int r = mp[val].first;
            int c = mp[val].second;
            row[r]++;
            if(row[r] == m)return i;
            col[c]++;
            if(col[c] == n)return i;
        }
        return -1;
    }
};