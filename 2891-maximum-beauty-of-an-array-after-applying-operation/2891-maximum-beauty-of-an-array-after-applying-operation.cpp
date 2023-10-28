class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        map<int,int> mp;
        int n = nums.size();
        vector<vector<int>> v;
        for(int i = 0;i<n;i++){
            v.push_back({nums[i] - k, nums[i] + k});
        }
        // return 0;
        for(int i = 0;i<v.size();i++){
            mp[v[i][0]]+=1;
            mp[v[i][1] + 1]-=1;
        }

        int mx = 0, sum = 0;
        for(auto &it : mp){
            sum += it.second;
            mx = max(mx,sum);
        }
        return mx;
    }
};