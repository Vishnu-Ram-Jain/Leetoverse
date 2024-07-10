class Solution {
public:
    int dp[501][501];
    int f(string &s, string &t, int i, int j){
        if(j < 0)return i+1;
        if(i < 0)return j+1;
        if(dp[i][j] != -1)return dp[i][j];

        if(s[i] == t[j]){
            return dp[i][j] = 0 + f(s,t,i-1,j-1);
        }
        else{
            int ins = 1 + f(s,t,i,j-1);
            int del = 1 + f(s,t,i-1,j);
            int rep = 1 + f(s,t,i-1,j-1);

            return dp[i][j] = min({ins,del,rep});
        }
    }
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        int n = word1.size();
        int m = word2.size();
        return f(word1,word2,n-1,m-1);
    }
};