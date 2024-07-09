class Solution {
public:
    int f(int ind, vector<int> &nums, int n, vector<int> &dp){
        if(ind >= n)return 0;
        if(dp[ind] != -1)return dp[ind];

        int pick = nums[ind] + f(ind+2,nums,n,dp);
        int notpick = 0 + f(ind+1,nums,n,dp);

        return dp[ind] = max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)return nums[0];
        vector<int> dp1(n+1,-1);
        vector<int> dp2(n+1,-1);
        int ans1 = f(0,nums,n-1,dp1);
        int ans2 = f(1,nums,n,dp2);

        return max(ans1,ans2);
    }
};