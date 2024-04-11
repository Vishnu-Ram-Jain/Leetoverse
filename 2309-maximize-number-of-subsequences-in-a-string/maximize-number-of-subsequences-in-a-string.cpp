class Solution {
public:
    typedef long long ll;
    ll f(string &x, string &y, int i, int j, vector<vector<ll>> &dp){
        if(j<0)return 1;
        if(i<0)return 0;
        if(dp[i][j] != -1)return dp[i][j];

        if(x[i] == y[j])return dp[i][j] = f(x,y,i-1,j-1,dp) + f(x,y,i-1,j,dp);
        else return dp[i][j] = f(x,y,i-1,j,dp);
    }
    long long maximumSubsequenceCount(string text, string pattern) {
        string x = pattern[0] + text;
        string y = text + pattern[1];
        int n = x.size();
        vector<vector<ll>> dp1(n+1,vector<ll>(3,-1));
        vector<vector<ll>> dp2(n+1,vector<ll>(3,-1));
        ll ans1 = f(x,pattern,n-1,1,dp1);
        ll ans2 = f(y,pattern,n-1,1,dp2);

        return max(ans1,ans2);
    }
};