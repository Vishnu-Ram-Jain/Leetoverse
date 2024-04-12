class Solution {
public:
    int dp[1001][1001];
    int Solve(string &text1,string &text2, int n, int m){
        // base case;
        if(n==0 || m==0){
            return 0;
        }

        // memoization;
        if(dp[n][m] != -1){
            return dp[n][m];
        }

        // choice diagram;
        if(text1[n-1] == text2[m-1]){
            return dp[n][m] = text1[n-1] + Solve(text1,text2,n-1,m-1);
        }
        else{
            return dp[n][m] = max(Solve(text1,text2,n-1,m) , Solve(text1,text2,n,m-1));
        }

    }
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        memset(dp,-1,sizeof(dp));
        string s;
        int lcs = Solve(s1,s2,n,m);

 
        int sum = 0;
        for(int i=0;i<n;i++){
            sum+=s1[i];
        }
        for(int i=0;i<m;i++){
            sum+=s2[i];
        }
        return sum - 2*lcs;
    }
};