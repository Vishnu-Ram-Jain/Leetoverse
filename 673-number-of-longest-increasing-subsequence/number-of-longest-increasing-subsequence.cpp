class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        vector<int> cnt(n,1);
        int len = 0;
        int ind = 0;
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(nums[i] > nums[prev]){
                    if(1 + dp[prev] > dp[i]){
                        dp[i] = 1 + dp[prev];
                        cnt[i] = cnt[prev];
                    }
                    else if(1 + dp[prev] == dp[i]){
                        cnt[i] += cnt[prev];
                    }
                }
            }

            if(len < dp[i]){
                len = dp[i];
                ind = i;
            }
        }
        int sum = 0;
        for(int i=0;i<n;i++){
            if(dp[i] == len)sum += cnt[i];
        }
        return sum;
    }
};