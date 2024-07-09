class Solution {
public:
    int dp[101];
    int f(int ind, vector<int> &nums, int n){
        if(ind >= n)return 0;
        if(dp[ind] != -1)return dp[ind];

        int pick = nums[ind] + f(ind+2,nums,n);
        int notpick = 0 + f(ind+1,nums,n);

        return dp[ind] = max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        memset(dp,-1,sizeof(dp));
        return f(0,nums,n);
    }
};