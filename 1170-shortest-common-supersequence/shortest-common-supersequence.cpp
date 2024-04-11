class Solution {
public:
    int dp[1001][1001];
    int f(string &x, string &y, int i, int j){
        if(i <= 0 or j <= 0)return 0;
        if(dp[i][j] != -1)return dp[i][j];

        if(x[i-1] == y[j-1])return dp[i][j] = 1 + f(x,y,i-1,j-1);
        else return dp[i][j] = max(f(x,y,i-1,j),f(x,y,i,j-1));
    }
    string shortestCommonSupersequence(string x, string y) {
        memset(dp,-1,sizeof(dp));
        int n = x.size();
        int m = y.size();
        f(x,y,n,m);

        int i=n,j=m;
        string ans = "";
        while(i>0 && j>0){
            if(x[i-1] == y[j-1]){
                ans += x[i-1];
                i--,j--;
            }
            else{
                if(dp[i-1][j] > dp[i][j-1]){
                    ans += x[i-1];
                    i--;
                }
                else{
                    ans += y[j-1];
                    j--;
                }
            }
        }
        while(i > 0){
            ans += x[i-1];
            i--;
        }
        while(j > 0){
            ans += y[j-1];
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};