class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> dp(n,1);
        vector<int> hash(n,0);

        int lastind = 0;
        int len = 0;
        for(int i=0;i<n;i++){
            hash[i] = i;
            for(int prev=0;prev<i;prev++){
                if(nums[i] % nums[prev] == 0 && 1 + dp[prev] > dp[i]){
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }
            if(len < dp[i]){
                len = dp[i];
                lastind = i;
            }
        }
        vector<int> ans;
        ans.push_back(nums[lastind]);
        while(hash[lastind] != lastind){
            lastind = hash[lastind];
            ans.push_back(nums[lastind]);
        }
        return ans;
    }
};