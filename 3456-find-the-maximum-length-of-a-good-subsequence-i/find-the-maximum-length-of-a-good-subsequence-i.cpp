class Solution {
public:
    int dp[502][502][26];
    int f(vector<int> &nums, int k, int i, int prev, int n){
        if(i >= n)return 0;
        // if(k < 0)return 0;

        if(dp[i][prev+1][k] != -1)return dp[i][prev+1][k];


        int pick = 0;
        int notpick = 0;
        if(prev == -1){
            pick = 1 + f(nums,k,i+1,i,n);
            notpick = f(nums,k,i+1,prev,n);
        }
        else{
            if(nums[i] == nums[prev]){
                pick = 1 + f(nums,k,i+1,i,n);
                notpick = f(nums,k,i+1,prev,n);
            }
            else{
                if(k-1 >= 0) pick = 1 + f(nums,k-1,i+1,i,n);
                notpick = f(nums,k,i+1,prev,n);
            }
        }


        return dp[i][prev+1][k] = max(pick,notpick);

    }
    int maximumLength(vector<int>& nums, int k) {
        memset(dp,-1,sizeof(dp));
        int n = nums.size();
        unordered_map<int,int> mp;
        int maxi = 0;
        if(k == 0){
            for(auto &i : nums){
                mp[i]++;
                maxi = max(maxi,mp[i]);
            }
            return maxi;
        }
        return f(nums,k,0,-1,n);
    }
};