class Solution {
public:
    int mod = 1e9 + 7;
    int dp[1001][1001];
    int f(int ind, int n, int steps){
        if(steps == 0){
            if(ind == 0)return 1;
            return 0;
        }
        if(ind >= n || ind < 0)return 0;
        if(dp[steps][ind] != -1)return dp[steps][ind];

        int op1 = 0 ;
        if(ind > 0)op1 = f(ind-1,n,steps-1) % mod;
        int op2 =  f(ind+1,n,steps-1) % mod;
        int op3 = f(ind,n,steps-1) % mod;

        return dp[steps][ind] = ((op1 % mod) + ((op2 % mod) + (op3 % mod))%mod) % mod;
    }
    int numWays(int steps, int arrLen) {
        memset(dp,-1,sizeof(dp));
        return f(0,arrLen,steps);
    }
};