class Solution {
public:
    int dp[1001][1001];
	int f(vector<int> &arr, int n, int i, int tar){
	    if(i >= n){
            if(tar == 0)return 0;
            else return -1e9;
        }
	    if(tar < 0)return -1e9;
	    if(dp[i][tar] != -1)return dp[i][tar];
	    
	    int pick = 1 + f(arr,n,i+1,tar-arr[i]);
	    int notpick = 0 + f(arr,n,i+1,tar);
	    
	    return dp[i][tar] = max(pick,notpick);
	}
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        int n = nums.size();
	    int ans = f(nums,n,0,target);
	    return ans < 0 ? -1 : ans;
    }
};