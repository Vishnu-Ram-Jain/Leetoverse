class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        if(a[0] == b[0])return a[1] < b[1];
        return a[0] <= b[0];
    }
    vector<vector<int>> insert(vector<vector<int>>& i, vector<int>& newi) {
        vector<vector<int>> v;
        i.push_back(newi);
        sort(i.begin(),i.end(),cmp);
        v.push_back(i[0]);
        int n = i.size();

        for(int j=1;j<n;j++){
            if(v.back()[1] >= i[j][0]){ // merging req;
                v.back()[1] = max(v.back()[1],i[j][1]);
            }
            else{
                v.push_back(i[j]);
            }
        }
        return v;
    }
};