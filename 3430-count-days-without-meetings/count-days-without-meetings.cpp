class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
        ans.push_back(arr[0]);

        for(int i=1;i<n;i++){
            if(ans.back()[1] >= arr[i][0]){
                ans.back()[1] = max(ans.back()[1],arr[i][1]);
            }
            else{
                ans.push_back(arr[i]);
            }
        }
        return ans;
    }
    int countDays(int days, vector<vector<int>>& m) {
        m = merge(m);
        int sum = 0;
        for(auto &i : m){
            sum += (i[1] - i[0] + 1);
        }
        return days - sum;
    }
};