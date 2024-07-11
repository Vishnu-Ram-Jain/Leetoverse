class Solution {
public:
    // int dp[2501][2501];
    // int f(int i, int prev_i, vector<int> &nums){
    //     if(i >= nums.size())return 0;

    //     if(dp[i][prev_i+1] != -1)return dp[i][prev_i+1];
        
    //     int pick = 0;
    //     if(prev_i == -1 or nums[i] > nums[prev_i]){
    //         pick = 1 + f(i+1,i,nums);
    //     }
    //     int np = f(i+1,prev_i,nums);

    //     return dp[i][prev_i+1] = max(pick,np);
    // }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));

        for(int i=n-1;i>=0;i--){
            for(int prev=i-1;prev>=-1;prev--){
                int pick = 0;
                if(prev == -1 or nums[i] > nums[prev]){
                    pick = 1 + dp[i+1][i+1];
                }
                int np = dp[i+1][prev+1];
                dp[i][prev+1] = max(pick,np);
            }
        }
        return dp[0][0];
    }
};