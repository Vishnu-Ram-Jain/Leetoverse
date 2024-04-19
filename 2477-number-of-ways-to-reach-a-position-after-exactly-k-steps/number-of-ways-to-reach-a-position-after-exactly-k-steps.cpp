class Solution {
public:
    int mod = 1e9 + 7;
    int dp[1001][5002];
    int f(int pos, int e, int k){
        if(k == 0){
            if(pos == e)return 1;
            return 0;
        }
        if(dp[k][pos+1000] != -1)return dp[k][pos+1000];
        int op2 = f(pos-1,e,k-1);
        int op1 = f(pos+1,e,k-1);

        return dp[k][pos+1000] = ((op1 % mod) + (op2 % mod)) % mod;

    }
    int numberOfWays(int startPos, int endPos, int k) {
        memset(dp,-1,sizeof(dp));
        return f(startPos,endPos,k);
    }
};