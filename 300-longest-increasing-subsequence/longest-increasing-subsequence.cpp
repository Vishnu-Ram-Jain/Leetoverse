class Solution {
public:
    int dp[2501][2501];
    int f(int i, int prev_i, vector<int> &nums){
        if(i >= nums.size())return 0;

        if(dp[i][prev_i+1] != -1)return dp[i][prev_i+1];
        
        int pick = 0;
        if(prev_i == -1 or nums[i] > nums[prev_i]){
            pick = 1 + f(i+1,i,nums);
        }
        int np = f(i+1,prev_i,nums);

        return dp[i][prev_i+1] = max(pick,np);
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return f(0,-1,nums);
    }
};