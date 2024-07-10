class Solution {
public: 
    int dp[1001][1001];
    int f(string &s, string &t, int n, int m){
        if(m < 0)return 1;
        if(n < 0)return 0;
        if(dp[n][m] != -1)return dp[n][m];

        if(s[n] == t[m]){
            return dp[n][m] = (f(s,t,n-1,m) + f(s,t,n-1,m-1));
        }
        else return dp[n][m] = f(s,t,n-1,m);
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        memset(dp,-1,sizeof(dp));
        return f(s,t,n-1,m-1);
    }
};