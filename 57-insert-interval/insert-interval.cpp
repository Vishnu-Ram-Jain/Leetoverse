class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& arr, vector<int>& newi) {
        int x = newi[0];
        int y = newi[1];
        int n = arr.size();
        int i = 0;
        vector<vector<int>> ans;
        while(i < n && arr[i][1] < x){
            ans.push_back(arr[i++]);
        }

        while(i < n && y >= arr[i][0]){
            x = min(x,arr[i][0]);
            y = max(y,arr[i][1]);
            i++;
        }
        ans.push_back({x,y});
        while(i < n){
            ans.push_back(arr[i]);
            i++;
        }
        return ans;
    }
};