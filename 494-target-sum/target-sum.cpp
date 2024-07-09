class Solution {
public:
    int dp[21][2002];
    int f(int i, int t, vector<int> &nums, int n, int sum){
        if(i >= n){
            return sum == t ? 1 : 0;
        }

        if(dp[i][sum] != -1)return dp[i][sum];

        int pick = 0;
        if(t >= nums[i])pick = f(i+1,t,nums,n,sum+nums[i]);
        int np = f(i+1,t,nums,n,sum-nums[i]);

        return dp[i][sum] = pick + np;
    }
    int findTargetSumWays(vector<int>& nums, int t) {
        t += 1000;
        memset(dp,-1,sizeof(dp));
        return f(0,t,nums,nums.size(),1000);
    }
};