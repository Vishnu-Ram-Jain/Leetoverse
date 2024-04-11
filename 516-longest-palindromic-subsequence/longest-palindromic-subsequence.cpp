class Solution {
public:
    int dp[1001][1001];
    int f(string &x, string &y, int i, int j){
        if(i < 0 or j < 0)return 0;
        if(dp[i][j] != -1)return dp[i][j];

        if(x[i] == y[j])return dp[i][j] = 1 + f(x,y,i-1,j-1);
        else return dp[i][j] = max(f(x,y,i-1,j),f(x,y,i,j-1));
    }
    int longestPalindromeSubseq(string x) {
        memset(dp,-1,sizeof(dp));
        int n = x.size();
        string y = x;
        reverse(y.begin(),y.end());
        int m = y.size();
        return f(x,y,n-1,m-1);
    }
};