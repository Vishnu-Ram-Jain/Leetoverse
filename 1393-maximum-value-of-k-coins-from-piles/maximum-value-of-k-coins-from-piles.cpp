class Solution {
public:
    int dp[1001][2002];
    int f(int i, vector<vector<int>>& arr, int k){
        if(i >= arr.size())return 0;
        if(k == 0)return 0;

        if(dp[i][k] != -1)return dp[i][k];
        
        int np = f(i+1,arr,k);
        int p = 0;
        int sum = 0;
        for(int j=0;j<arr[i].size() && j+1<=k;j++){
            sum += arr[i][j];
            p = max(p,sum + f(i+1,arr,k-j-1));
        }
        return dp[i][k] = max(np,p);
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        memset(dp,-1,sizeof(dp));
        return f(0,piles,k);
    }
};