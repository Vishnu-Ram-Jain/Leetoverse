class Solution {
public:
vector<int> prefixsum(vector<int> &nums){
    int n = nums.size();
    vector<int> pre(n,0);

    pre[0] = nums[0];
    for(int i=1;i<n;i++){
        pre[i] = pre[i-1] + nums[i];
    }
    
    return pre;
}
    int leastBricks(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<vector<int>> pre;

        for(int i=0;i<n;i++){
            vector<int> temp = prefixsum(arr[i]);
            pre.push_back(temp);
        }
        int maxi = 0;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<pre[i].size()-1;j++){
                mp[pre[i][j]]++;
                maxi = max(maxi,mp[pre[i][j]]);
            }
        }

        return n - maxi;
    }
};