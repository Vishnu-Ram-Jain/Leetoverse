class Solution {
public:
    int minGroups(vector<vector<int>>& nums) {
        map<int,int> mp;
        int mx = 0;
        int sum = 0;
        int n = nums.size();

        for(auto it : nums){
            mp[it[0]]++;
            mp[it[1] + 1]--;
        }

        for(auto &it : mp){
            sum += it.second;
            mx = max(mx,sum);
        }
        return mx;
    }
};